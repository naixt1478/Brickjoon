#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge_sort(int*, int, int);
void merge(int*,int*,int,int,int,int);
void solve(int* arr1, int* parr1);

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    int* arr1 = (int*)calloc(N,sizeof(int));
    int* arr2 = (int*)calloc(M,sizeof(int));
    for(int i = 0; i < N; i++) scanf("%d", &arr1[i]);
    merge_sort(arr1, N, 0);
    solve(arr1, arr2);
    free(arr1);
    free(arr2);
    return 0;
}

void solve(int* arr1, int* parr1)
{
    
}

void merge_sort(int* arr, int len, int comp)
{  
    int* warr = (int*)malloc(len*sizeof(int));
    for(int i = 1; i < len; i*=2)
    {
        for(int j = 0; j < len; j += 2 * i)
            merge(arr, warr, j, min(j+i, len), min(j+i*2,len), comp);
        memcpy(arr, warr, len*sizeof(int));
    }
    free(warr);
}

void merge(int* arr, int* warr, int l1, int r1, int e1, int comp)
{
    int i = l1;
    int j = r1;
    for(int k = l1; k < e1; k++)
    {
        if(i < r1 && (j >= e1 || (arr[i] <= arr[j]) != comp))
        {
            warr[k] = arr[i];
            i++;
        }
        else
        {
            warr[k] = arr[j];
            j++;
        }
    }
}
