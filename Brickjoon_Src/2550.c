#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int sort_t;
int comp2(const void* a, const void* b);
int lower_bound(int* arr1, int l, int val);

int N;
int main(void)
{
    freopen("TestInput.txt", "r", stdin);
    freopen("TestOutput.txt", "w", stdout);
    scanf("%d", &N);
    int* sp1 = (int*)calloc(N, sizeof(int));
    int* sp2 = (int*)calloc(N, sizeof(int));
    int* sp3 = (int*)calloc(N, sizeof(int));
    for(int i = 0; i < N; i++)
        scanf("%d", &sp1[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &sp2[i]);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(sp1[i] == sp2[j])
                sp3[i] = j;
    int M = 0;
    int i1 = 0;
    int* ip1 = (int*)calloc(0, sizeof(int));
    int* dp2 = calloc(N, sizeof(int));
    int* bs1 = calloc(N, sizeof(int));
    for(int i = 0; i < N; i++)
    {
        int lb = lower_bound(bs1, M, sp3[i]);
        if(lb == -1)
        {
            bs1[M] = sp3[i];
            dp2[i] = M + 1;
            M += 1;
        }
        else
        {
            bs1[lb] = sp3[i];
            dp2[i] = lb + 1;
        }
    }
    int k = M;
    for(int i = N - 1; i >= 0; i--)
    {
        if(k == 0) break;
        if(dp2[i] == k)
        {
            ip1 = (int*)realloc(ip1, sizeof(int) * (i1 + 1));
            ip1[i1] = sp1[i];
            i1 += 1;
            k -= 1;
        }
    }
    qsort(ip1, i1, sizeof(int), comp2);
    printf("%d\n", i1);
    for(int i = 0; i < i1; i++)
        printf("%d ", ip1[i]);
    free(dp2);
    free(bs1);
    return 0;
}
// bottom-up sort
// comp 1 : 내림차순
// comp 0 : 오름차순
// len : 배열크기
// arr : 배열포인터(배열 주소)
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