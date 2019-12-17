#include <stdio.h>

int main()
{
    short int n = 1;
    int  c = *((char *) &n);
    if (c == 1)
        printf("Little-endian");
    else
        printf("Big-endian");
    return 0;
}
