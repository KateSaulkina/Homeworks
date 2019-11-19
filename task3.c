#include <stdio.h>
#include <stdlib.h>
#define size 256

int main()
{
    int N;
    scanf("%d", &N);
    int s;
    int order = 1;
    int num1[size] = {0};
    int reit[size] = {0};
    for (int i = 0; i < N; i++) {
        scanf("%d", &s);
        reit[s] += 1;
        if (reit[s] == 1) {
            num1[s] = order;
            ++order;
        }
    }
    for (int i = 1; i <= size; i++) {
        for (int j = 0; j < size; j++) {
            if (num1[j] == i) {
                printf("%d ", j);
            }
        }
    }
    return 0;
}
