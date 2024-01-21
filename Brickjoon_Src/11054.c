#define max(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n, m = 1,a;
    scanf("%d", &n);
    int* arr1 = (int*)malloc(sizeof(int) * n);
    int* arr2 = (int*)malloc(sizeof(int) * n);
    int* arr3 = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
        arr2[i] = 1;
        arr3[i] = 1;
        for(int j = 0; j < i; j++)
            if(arr1[j] < arr1[i]) arr2[i] = max(arr2[j] + 1, arr2[i]);
    }
    for(int i = n - 2; i >= 0; i--)
    {
        for(int j = n - 1; j > i; j--)
        {
            if(arr1[i] > arr1[j])
                arr3[i] = max(arr3[j]+1, arr3[i]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        a = arr2[i] + arr3[i] - 1;
        if(a > m) m = a;
    }
    printf("%d", m);
    return 0;
}