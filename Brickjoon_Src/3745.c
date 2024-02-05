// from 14003
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lower_bound(int* arr1, int l, int val);
void solve(int n);

int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF)
        solve(n);
}

void solve(int n)
{
    int M = 0;
    int* pi1 = calloc(n, sizeof(int));
    int* dp1 = calloc(n, sizeof(int));
    int* dp2 = calloc(n, sizeof(int));
    int* bs1 = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &pi1[i]);
        int lb = lower_bound(bs1, M, pi1[i]);
        if(lb == -1)
        {
            bs1[M] = pi1[i];
            dp2[i] = M + 1;
            M += 1;
        }
        else
        {
            bs1[lb] = pi1[i];
            dp2[i] = lb + 1;
        }
    }
    int k = M;
    for(int i = n - 1; i >= 0; i--)
    {
        if(dp2[i] == k)
        {
            dp1[k] = pi1[i];
            k -= 1;
            if(k == 0) break;
        }
    }
    printf("%d\n",M);
    free(pi1);
    free(dp1);
    free(dp2);
    free(bs1);
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