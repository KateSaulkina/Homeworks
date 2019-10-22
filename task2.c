#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100];
    scanf("%s", &s);
    int i = 0;
    int n = 0;
    while(s[i]) {
        n = n * 10;
        n = n + (s[i] - '0');
        i++;
    }
    printf("%d", n);
    return 0;
}
