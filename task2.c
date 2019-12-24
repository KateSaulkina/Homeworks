#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100];
    scanf("%s", &s);
    int i = 0;
    int res = 0;
    while(s[i]) {
        if ('0' <= s[i] && s[i] <= '9'){
            res = res * 10;
            res = res + (s[i] - '0');
            i++;
        }
    }
    printf("%d", res);
    return 0;
}
