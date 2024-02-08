#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N,K;
int comp(const void* a,const void* b);

int main(void)
{
    scanf("%d %d", &N, &K);
    int* arr = (int*)calloc(N, sizeof(int));
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    qsort(arr, N, sizeof(int), comp);
    printf("%d", arr[K - 1]);
    return 0;
}

int comp(const void* a,const void* b)
{
    if(*(int*)a > *(int*)b) return 1;
    else if(*(int*)a < *(int*)b) return -1;
    else return 0;
}