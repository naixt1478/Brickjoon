#include <stdio.h>
#include <stdlib.h>
int n,m;

int s1(int, int, int **, int **);

int main(void)
{
    scanf("%d", &n);
    int **arr1 = calloc(n,sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        arr1[i] = (int *)calloc(i + 1, sizeof(int));
        for(int j = 0; j < i + 1; j++)
            scanf("%d", &arr1[i][j]);
    }
    int **arr2 = calloc(n,sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        arr2[i] = (int *)calloc(i + 1, sizeof(int));
        for(int j = 0; j < i + 1; j++)
            arr2[i][j] = -1;
    }
    m = s1(0, 0, arr1, arr2);
    printf("%d", m);
    //free() phase
    for(int i = 0; i < n; i++)
        free(arr1[i]);
    free(arr1);
    return 0;
}

int s1(int a, int b, int **arr, int **dp)
{
    int l = arr[a][b];
    if(dp[a][b] != -1)
        return dp[a][b];
    else if(a < n-1)
    {
        int r1 = s1(a + 1, b, arr, dp);
        int r2 = s1(a + 1, b + 1, arr, dp);
        if(r1 > r2) 
        {
            dp[a][b] = l + r1;
            return l + r1;
        }
        else 
        {
            dp[a][b] = l + r2;
            return l + r2;
        }
    }
    else
    {
        dp[a][b] = l;
        return l;
    }
    return 0;
}
