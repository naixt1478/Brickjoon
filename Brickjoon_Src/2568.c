#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sort_t
{
    int A,B;
} sort_t;

void merge_sort(sort_t* arr, int len, int (*comp)(void*,void*));
void merge(sort_t* arr, sort_t* warr,int l1,int r1,int e1,int (*comp)(void*,void*));
int comp(void* a, void* b);
int comp2(const void* a, const void* b);

int lower_bound(int* arr1, int l, int val);

int N;
int main(void)
{
    //freopen("TestInput.txt", "r", stdin);
    //freopen("TestOutput.txt", "w", stdout);
    scanf("%d", &N);
    sort_t* sp1 = (sort_t*)calloc(N, sizeof(sort_t));
    for(int i = 0; i < N; i++)
        scanf("%d %d", &sp1[i].A, &sp1[i].B);
    merge_sort(sp1, N, comp);
    int M = 0;
    int i1 = 0;
    int* ip1 = (int*)calloc(0, sizeof(int));
    int* dp1 = calloc(N, sizeof(int));
    int* dp2 = calloc(N, sizeof(int));
    int* bs1 = calloc(N, sizeof(int));
    for(int i = 0; i < N; i++)
    {
        int lb = lower_bound(bs1, M, sp1[i].B);
        if(lb == -1)
        {
            bs1[M] = sp1[i].B;
            dp2[i] = M + 1;
            M += 1;
        }
        else
        {
            bs1[lb] = sp1[i].B;
            dp2[i] = lb + 1;
        }
    }
    int k = M;
    for(int i = N - 1; i >= 0; i--)
    {
        if(dp2[i] == k)
        {
            dp1[k] = sp1[i].B;
            k -= 1;
        }
        else
        {
            ip1 = (int*)realloc(ip1, sizeof(int) * (i1 + 1));
            ip1[i1] = sp1[i].A;
            i1 += 1;
        }
    }
    qsort(ip1, i1, sizeof(int), comp2);
    printf("%d\n", i1);
    for(int i = 0; i < i1; i++)
        printf("%d\n", ip1[i]);
    free(dp1);
    free(dp2);
    free(bs1);
    return 0;
}
// bottom-up sort
// comp 1 : 내림차순
// comp 0 : 오름차순
// len : 배열크기
// arr : 배열포인터(배열 주소)
int comp(void* a, void* b)
{
    sort_t *L = a, *R = b;
    if(L->A <= R->A) return 1;
    else return 0;
}

int comp2(const void* a, const void* b)
{
    if(*(int*)a > *(int*)b)
        return 1;
    else if(*(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}

int lower_bound(int* arr1, int l, int val)
{
    int s = 0; 
    int e = l - 1;
    int mid = e;
    while(s < e)
    {
        mid = (s + e) / 2;
        if(arr1[mid] < val)
            s = mid + 1;
        else
            e = mid;
    }
    if(arr1[e] < val) return -1;
    return e;
}

void merge_sort(sort_t* arr, int len, int (*comp)(void*,void*))
{  
    sort_t* warr = (sort_t*)malloc(len*sizeof(sort_t));
    for(int i = 1; i < len; i*=2)
    {
        for(int j = 0; j < len; j += 2 * i)
            merge(arr, warr, j, min(j+i, len), min(j+i*2,len), comp);
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
