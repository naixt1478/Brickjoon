#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N,M,S;
int main(void)
{
    scanf("%d %d", &N, &M);
    int** arr1 = calloc(N, sizeof(int*));
    for(int i = 0; i < N; i++)
    {
        arr1[i] = calloc(M,sizeof(int));
        for(int j = 0; j < M; j++)
            scanf("%d", &arr1[i][j]);
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // I
            if(M-j >= 4)
                S = max(S, arr1[i][j] + arr1[i][j+1] + arr1[i][j+2] + arr1[i][j+3]);
            if(N-i >= 4)
                S = max(S, arr1[i][j] + arr1[i+1][j] + arr1[i+2][j] + arr1[i+3][j]);
            // 4 mino
            if(M-j >= 2 && N-i >= 2)
                S = max(S, arr1[i][j] + arr1[i][j+1] + arr1[i+1][j] + arr1[i+1][j+1]);
            // L mino original
            if(M-j >= 2 && N-i >= 3)
            {
                S = max(S, arr1[i][j] + arr1[i+1][j] + arr1[i+2][j] + arr1[i+2][j+1]);
                S = max(S, arr1[i][j] + arr1[i][j+1] + arr1[i+1][j+1] + arr1[i+2][j+1]);
                S = max(S, arr1[i][j] + arr1[i][j+1] + arr1[i+1][j] + arr1[i+2][j]);
                S = max(S, arr1[i][j+1] + arr1[i+1][j+1] + arr1[i+2][j+1] + arr1[i+2][j]);
            }
            if(M-j >= 3 && N-i >= 2)
            {
                S = max(S, arr1[i][j] + arr1[i+1][j] + arr1[i][j+1] + arr1[i][j+2]);
                S = max(S, arr1[i+1][j] + arr1[i+1][j+1] + arr1[i+1][j+2] + arr1[i][j+2]);
                S = max(S, arr1[i][j] + arr1[i][j+1] + arr1[i][j+2] + arr1[i+1][j+2]);
                S = max(S, arr1[i][j] + arr1[i+1][j] + arr1[i+1][j+1] + arr1[i+1][j+2]);
            }
            // S mino
            if(M-j >= 2 && N-i >= 3)
            {
                S = max(S, arr1[i][j] + arr1[i+1][j] + arr1[i+1][j+1] + arr1[i+2][j+1]);
                S = max(S, arr1[i+2][j] + arr1[i+1][j] + arr1[i+1][j+1] + arr1[i][j+1]);
            }
            if(M-j >= 3 && N-i >= 2)
            {
                S = max(S, arr1[i+1][j] + arr1[i+1][j+1] + arr1[i][j+1] + arr1[i][j+2]);
                S = max(S, arr1[i][j] + arr1[i][j+1] + arr1[i+1][j+1] + arr1[i+1][j+2]);
            }
            // T mino
            if(M-j >= 3 && N-i >= 2)
            {
                S = max(S, arr1[i][j] + arr1[i][j+1] + arr1[i+1][j+1] + arr1[i][j+2]);
                S = max(S, arr1[i+1][j] + arr1[i+1][j+1] + arr1[i][j+1] + arr1[i+1][j+2]);
            }
            if(M-j >= 2 && N-i >= 3)
            {
                S = max(S, arr1[i+1][j] + arr1[i][j+1] + arr1[i+1][j+1] + arr1[i+2][j+1]);
                S = max(S, arr1[i][j] + arr1[i+1][j] + arr1[i+2][j] + arr1[i+1][j+1]);
            }
        }
    }
    printf("%d", S);
    return 0;
}