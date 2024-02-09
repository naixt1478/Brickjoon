// from 11403 solve or 1389 solvex`
// 
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    int** i1 = (int**)malloc(sizeof(int*)*(N+1));
    for(int i = 1; i <= N; i++)
    {
        i1[i] = (int*)calloc(N+1,sizeof(int));
        for(int j = 1; j <= N; j++)
            scanf("%d", &i1[i][j]);
    }
    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                if(i1[i][k] == 1 && i1[k][j] == 1) 
                    i1[i][j] = 1;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            printf("%d ", i1[i][j]);
        printf("\n");
    }
    for(int i = 1; i <= N; i++)
        free(i1[i]);
    free(i1);
    return 0;
}
