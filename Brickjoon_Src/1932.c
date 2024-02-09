#include <stdio.h>
#include <stdlib.h>
<<<<<<< Updated upstream
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
=======
int n;
int sum1(int a, int b, int **arr2);
int main(void)
{
    scanf("%d", &n);
    int **arr2 = calloc(n, sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        arr2[i] = (int*)calloc(i+1, sizeof(int));
        for(int j = 0; j <= i; j++)
            scanf("%d ", &arr2[i][j]);
    }
    printf("%d", sum1(0, 0, &arr2));
    for(int i = 0; i < n; i++)
        free(arr2[i]);
    free(arr2);
    return 0;
}

int sum1(int a, int b, int **arr2)
{
    if(a >= n-1)
        return arr2[a][b];
    int c = sum1(a+1, b, &arr2);
    int d = sum1(a+1, b+1, &arr2);
    if(c > d)
        return arr2[a][b] + c;
    else
        return arr2[a][b] + d;
}
>>>>>>> Stashed changes
