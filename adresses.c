#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a;
int b = 100;
char s = 's';
void func(void){
    int x;
    int y;
    printf("adress x:  %p\n", &x);
    printf("adress y:  %p\n", &y);
}
void func2(void){
}

int main()
{
    func();
    char d = 'd';
    int n = 5;
    int* data = malloc(n * sizeof(int));
    if (data == NULL) {
        printf("ERROR");
    }
    int* data1 = malloc(b * sizeof(int));
    if (data1 == NULL) {
        printf("ERROR");
    }
    printf("adress a:  %p\n", &a);
    printf("adress b:  %p\n", &b);
    printf("adress s:  %p\n", &s);
    printf("adress func:  %p\n", &func);
    printf("adress func2:  %p\n", &func2);
    printf("adress printf:  %p\n", &printf);
    printf("adress strcpy:  %p\n", &strcpy);
    printf("adress n:  %p\n", &n);
    printf("adress d:  %p\n", &d);
    printf("adress data:  %p\n", data);
    printf("adress data1:  %p\n", data1);
    free(data);
    free(data1);
    return 0;
}
