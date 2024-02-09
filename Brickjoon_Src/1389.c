#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N,M,a,b,sum,m1[2];
    scanf("%d %d", &N, &M);
    int** i1 = (int**)malloc(sizeof(int*)*(N+1));
    for(int i = 1; i <= N; i++)
    {
        i1[i] = (int*)calloc(N+1,sizeof(int));
        for(int j = 1; j<= N; j++)
            if(i!=j) i1[i][j] = 99999;
    }
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        i1[a][b] = 1;
        i1[b][a] = 1;
    }
    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                i1[i][j] = (i == j ? 0 : min(i1[i][j], i1[i][k] + i1[k][j]));
    for(int i = 1; i <= N; i++)
    {
        sum = 0;
        for(int j = 1; j <= N; j++)
            sum += i1[i][j];
        if(i == 1 || m1[0] > sum)
        {
            m1[0] = sum;
            m1[1] = i;
        }
    }
    printf("%d", m1[1]);
    for(int i = 1; i <= N; i++)
        free(i1[i]);
    free(i1);
    return 0;
}
