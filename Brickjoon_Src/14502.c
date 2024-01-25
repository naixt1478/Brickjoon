#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int N, M, a;
int main(void)
{
    scanf("%d %d", &N, &M);
    int** ppi1 = (int**)malloc(sizeof(int*) * N);
    for(int i = 0; i < N; i++) 
    {
        ppi1[i] = (int*)calloc(M, sizeof(int));
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &ppi1[i][j]);
            if(ppi1[i][j] == 0) a += 1;
        }
    }
    for(int i = 0;)
    return 0;
}
