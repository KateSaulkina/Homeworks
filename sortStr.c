#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <malloc.h>
#include <sys/stat.h>
#include "mman.h"


int Strcmp(void* point1, void* point2) {
	char *s1;
	char *s2;
	s1 = *(char**)point1;
	s2 = *(char**)point2;
	return strcmp(s1, s2);
}

void copyAdrStr(char **strings, char *input) {
    size_t i = 0;
    size_t adr = 0;
    size_t inp = 0;
    while (input[i])
    {
        if (input[i] == '\n') {
            strings[adr] = &input[inp];
            adr++;
            inp = i + 1;
        }
        i++;
    }
}

int main() {
    int fInp = open("text.txt", O_RDWR, 0);
    if (fInp < 0)
    {
        printf("Error open file");
        exit(1);
    }
    FILE* fOut = fopen("out.txt", "w");
    if (fOut == NULL)
    {
        printf("Error open file");
        exit(1);
    }

    struct stat inf;
	fstat(fInp, &inf);
	size_t size = inf.st_size;
    char* input = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fInp, 0);
    int inputLen = strlen(input);
    int maxI = 0, helper = 0;
    size_t kStr = 0;
    for (size_t i = 0; i < inputLen; i++)
    {
        if (input[i] == '\n')
        {
            kStr++;
        }
    }

    char **str = (char**)malloc(kStr * sizeof(char*));
    if (str == NULL)
    {
        printf("ERROR");
        exit(1);
    }

    copyAdrStr(str, input);
    qsort(str, kStr, sizeof(char*), Strcmp);

    for (size_t i = 0; i < kStr; i++)
    {
        size_t j = 0;
        while (str[i][j] != '\n')
        {
            fputc(str[i][j], fOut);
            j++;
        }
    }

    close(fInp);
    fclose(fOut);
    free(str);
    munmap(input, inputLen);

    return 0;
}
