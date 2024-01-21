#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int T,N,M;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        int* arr1 = (int*)malloc(sizeof(int) * N);
        for(int i = 0; i < N; i++) scanf("%d", &arr1[i]);
        scanf("%d", &M);
        int* arr2 = (int*)calloc((M + 1),sizeof(int));
        arr2[0] = 1;
        for(int i = 0; i < N; i++)
        {
            for(int j = arr1[i]; j <= M; j++)
                arr2[j] = arr2[j - arr1[i]] + arr2[j];
        }
        printf("%d\n", arr2[M]);
        free(arr2);
        free(arr1);
    }
    return 0;
}