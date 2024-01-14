#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N,M,s,a,b;

int solve(int*, char*, int L);
int main(void)
{
    int* arr1 = (int*)calloc(10, sizeof(int));
    char* c1 = (char*)malloc(10*sizeof(char));
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &a);
        arr1[a] = 1;
    }
    s = abs(N - 100);
    if(M != 10)
    {
        for(int j = 0; j <= 999999; j++)
        {
            sprintf(c1, "%d", j);
            b = strlen(c1);
            if(solve(arr1, c1, b))
            {
                s = min(s, abs(N - j) + b);
            }
        }
    }
    printf("%d", s);
    return 0;
}

int solve(int* arr1, char* arr2, int L)
{
    for(int i = 0; i < L; i++)
        if(arr1[arr2[i] - '0']) return 0;
    return 1;
}
