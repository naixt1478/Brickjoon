#define max(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n,M = 1;
    scanf("%d", &n);
    int* arr1 = (int*)malloc(sizeof(int) * n);
    int* arr2 = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr2[i]);
        arr1[i] = 1;
    }
    for(int i = n - 2; i >= 0; i--)
    {
        for(int j = n - 1; j > i; j--)
        {
            if(arr2[i] > arr2[j])
                arr1[i] = max(arr1[j]+1, arr1[i]);
            if(arr1[i] > M) M = arr1[i];
        }
    }
    printf("%d", M);
    return 0;
}