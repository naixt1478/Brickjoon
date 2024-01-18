#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int sort_t;

void merge_sort(sort_t* arr, int len, int comp);
void merge(sort_t* arr, sort_t* warr,int l1,int r1,int e1,int comp);
int comp(void* a, void* b);

int main(void)
{
    return 0;
}
// bottom-up sort
// comp 1 : 내림차순
// comp 0 : 오름차순
// len : 배열크기
// arr : 배열포인터(배열 주소)
int comp(void* a, void* b)
{
    if(*(int*)a <= *(int*)b) return 1;
    else return 0;
}

void merge_sort(sort_t* arr, int len, int comp)
{  
    sort_t* warr = (sort_t*)malloc(len*sizeof(sort_t));
    for(int i = 1; i < len; i*=2)
    {
        for(int j = 0; j < len; j += 2 * i)
        {
            merge(arr, warr, j, min(j+i, len), min(j+i*2,len), comp);
        }
        memcpy(arr, warr, len*sizeof(sort_t));
    }
    free(warr);
}

void merge(sort_t* arr, sort_t* warr, int l1, int r1, int e1, int (*comp)(void*,void*))
{
    int i = l1;
    int j = r1;
    for(int k = l1; k < e1; k++)
    {
        if(i < r1 && (j >= e1 || (*comp)(&arr[i], &arr[j])))
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
