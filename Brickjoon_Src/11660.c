#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M, a, b, c, d;
int main(void)
{
    scanf("%d %d", &N, &M);
    int** m1 = (int**)malloc(sizeof(int*) * (N+1));
    int** dp1 = (int**)malloc(sizeof(int*) * (N+1));
    for(int i = 0; i <= N; i++)
    {
        m1[i] = (int*)calloc(N + 1, sizeof(int));
        dp1[i] = (int*)calloc(N + 1, sizeof(int));
        if(i != 0)
            for(int j = 1; j <= N; j++) scanf("%d", &m1[i][j]);
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            dp1[i][j] = dp1[i][j - 1] + dp1[i - 1][j] - dp1[i - 1][j - 1] + m1[i][j];
    }
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("%d\n", dp1[c][d] - dp1[a - 1][d] - dp1[c][b-1] + dp1[a - 1][b - 1]);
    }
    for(int i = 0; i <= N; i++)
    {
        free(m1[i]);
        free(dp1[i]);
    }
    free(m1);
    free(dp1);
    return 0;
}