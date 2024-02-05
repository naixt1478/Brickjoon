#define min(a,b) (((a)<(b))?(a):(b))
#define idx(a) ((a) - 'A')
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int lli;
lli N;
lli arr1[6];
int comp(const void* a, const void* b);

/*
 N >= 1
*/
int main(void)
{
    lli min1 = 51;
    lli min2 = 101;
    lli min3 = 151;
    lli l = 0;
    lli sum = 0;
    scanf("%lld", &N);
    for(lli i = 0; i < 6; i++) 
    {
        scanf("%lld", &arr1[i]);
        if(arr1[i] < min1) min1 = arr1[i];
        if(arr1[i] > l) l = arr1[i];
        sum += arr1[i];
    }
    min2 = min(min2, arr1[idx('A')] + arr1[idx('B')]);
    min2 = min(min2, arr1[idx('A')] + arr1[idx('D')]);
    min2 = min(min2, arr1[idx('A')] + arr1[idx('E')]);
    min2 = min(min2, arr1[idx('A')] + arr1[idx('C')]);

    min2 = min(min2, arr1[idx('F')] + arr1[idx('B')]);
    min2 = min(min2, arr1[idx('F')] + arr1[idx('D')]);
    min2 = min(min2, arr1[idx('F')] + arr1[idx('E')]);
    min2 = min(min2, arr1[idx('F')] + arr1[idx('C')]);

    min2 = min(min2, arr1[idx('B')] + arr1[idx('D')]);
    min2 = min(min2, arr1[idx('D')] + arr1[idx('E')]);
    min2 = min(min2, arr1[idx('E')] + arr1[idx('C')]);
    min2 = min(min2, arr1[idx('C')] + arr1[idx('B')]);

    min3 = min(min3, arr1[idx('A')] + arr1[idx('B')] + arr1[idx('D')]);
    min3 = min(min3, arr1[idx('A')] + arr1[idx('D')] + arr1[idx('E')]);
    min3 = min(min3, arr1[idx('A')] + arr1[idx('B')] + arr1[idx('C')]);
    min3 = min(min3, arr1[idx('A')] + arr1[idx('C')] + arr1[idx('E')]);
    min3 = min(min3, arr1[idx('D')] + arr1[idx('B')] + arr1[idx('F')]);
    min3 = min(min3, arr1[idx('B')] + arr1[idx('C')] + arr1[idx('F')]);
    min3 = min(min3, arr1[idx('F')] + arr1[idx('C')] + arr1[idx('E')]);
    min3 = min(min3, arr1[idx('F')] + arr1[idx('D')] + arr1[idx('E')]);
    lli a = 0;
    if(N == 1)
        printf("%lld", sum - l);
    else
    {
        a += min3 * 4;
        a += (N - 1) * 4 * min2;
        if(N >= 3)
        {
            a += (N - 2) * 4 * min2;
            a += (N*N - 3*N + 2)*4*min1;
            a += (N*N - 4*N + 4)*min1;
        }
        printf("%lld", a);
    }
    return 0;
}

int comp(const void* a, const void* b)
{
    if(*(lli*)a > *(lli*)b) return 1;
    else if(*(lli*)a < *(lli*)b) return -1;
    else return 0;
}