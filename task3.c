#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int s;
    int res[10000];
    char n[256] = {0};
    for (int i = 0; i < N; i++){
        scanf("%d", &s);
        n[s] += 1;
        if (n[s] == 1){
            res[i] = s;
        }
    }
    for (int j = 0; j < N; j++){
        if(res[j] != 0){
            printf("%d ", res[j]);
        }
    }
    return 0;
}
