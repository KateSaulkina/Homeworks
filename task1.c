#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));
    return 0;
}
