#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Error: negative number");
    } else {
        printf("Fibonacci number: %d", fib(n));
    }
    return 0;
}
