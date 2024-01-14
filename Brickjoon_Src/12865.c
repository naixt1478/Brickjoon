#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N,K;
    scanf("%d %d", &N, &K);
    int** arr1 = (int**)calloc(N+1,sizeof(int*));
    int** arr2 = (int**)calloc(N+1,sizeof(int*));
    for(int i = 0; i <= N; i++)
    {
        arr1[i] = (int*)calloc(K+1,sizeof(int));
        arr2[i] = (int*)calloc(2, sizeof(int));
        if(i == 0) continue;
        scanf("%d %d", &arr2[i][0], &arr2[i][1]);
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= K; j++)
        {
            if(arr2[i][0] > j)
                arr1[i][j] = arr1[i - 1][j];
            else
                arr1[i][j] = max(arr1[i - 1][j], arr1[i - 1][j - arr2[i][0]] + arr2[i][1]);
        }
    }
    printf("%d", arr1[N][K]);
    for(int i = 0; i < N; i++)
    {
        free(arr1[i]);
        free(arr2[i]);
    }
    free(arr1);
    free(arr2);
    return 0;
}