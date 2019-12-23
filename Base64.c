#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int main()
{
    int num = 0;
    char* s = malloc(10000);
    if (s == NULL) {
        printf("ERROR");
    }
    int mask = 63 << 18;
    scanf("%s", s);
    unsigned int len = strlen(s);
    int* out = malloc(len / 3 * 4 * sizeof(int));
    if (out == NULL) {
        printf("ERROR");
        exit(1);
    }
    for (size_t i = 0; i < (len - 2); i += 3) {
        for (size_t j = 0; j < 3; j++) {
            num = (num + (s[i + j] - '0' + 48)) << 8;
        }
        num = num >> 8;
        for (size_t l = 0; l < 4; l++) {
            out[(i / 3 * 4) + l] = (num & mask) >> 18;
            num = num << 6;
        }
        num = 0;
    }
    free(s);

    size_t i = 0;
    char c;
    while (i < len / 3 * 4) {
        if (out[i] <= 25)
            c = 65 + out[i];
        else if (out[i] <= 51)
            c = 71 + out[i];
        else if (out[i] <= 61)
            c = -4 + out[i];
        else if (out[i] == 62)
            c = 43;
        else if (out[i] == 63)
            c = 47;
        printf("%c", c);
        i++;
    }
    free(out);
    return 0;
}
