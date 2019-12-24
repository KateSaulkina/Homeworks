#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


void code(char* s, size_t len, size_t* out) {
    size_t mask = 63 << 18;
    int num = 0;
    for (size_t i = 0; i < (len - 2); i += 3) {
        for (size_t j = 0; j < 3; j++) {
            num = (num + (s[i + j] - '0' + 48)) << 8;
        }
        num = num >> 8;
        for (size_t l = 0; l < 4; l++) {
            out[i / 3 * 4 + l] = (num & mask) >> 18;
            num = num << 6;
        }
        num = 0;
    }
}

void decode(size_t* out, size_t lenO) {
    size_t i = 0;
    char c;
    while (i < lenO) {
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
}

int main()
{
    char* s = (char*) malloc(100 * sizeof(char));
    if (s == NULL) {
        printf("ERROR");
        exit(1);
    }
    scanf("%s", s);
    size_t len = strlen(s);
    if (len < 2) {
        exit(1);
    }
    size_t lenO = len / 3 * 4;
    size_t* out = (size_t*) malloc(lenO * sizeof(size_t));
    if (out == NULL) {
        printf("ERROR");
        exit(1);
    }
    code(s, len, out);
    free(s);
    decode(out, lenO);
    free(out);
    return 0;
}
