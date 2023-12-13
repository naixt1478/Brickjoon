#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_sort(int*, int, int);
void merge(int*,int*,int,int,int,int);

int main(void)
{
    return 0;
}
// bottom-up sort
// comp 1 : 내림차순
// comp 0 : 오름차순
// len : 배열크기
// arr : 배열포인터(배열 주소)
void merge_sort(int* arr, int len, int comp)
{  
    int* warr = (int*)malloc(len*sizeof(int));
    for(int i = 1; i < len; i*=2)
    {
        for(int j = 0; j < len; j += 2 * i)
        {
            merge(arr, warr, j, min(j+i, len), min(j+i*2,len), comp);
        }
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
