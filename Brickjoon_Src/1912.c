#include <stdio.h>
<<<<<<< Updated upstream
#include <stdlib.h>
int n;

int s1(int, int, int**, int **);
int main(void)
{
    scanf("%d", n);
    int *arr1 = calloc(n, sizeof(int));
    int *arr2 = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &arr1);
    printf("%d", s1(0, n-1, &arr1, &arr2));
    // free phase
    free(arr1);
    return 0;
}

int s1(int l, int r, int **p, int **p2)
{
    int s1 = 0;
    int *arr = *p;
    int *dp = *p2;
    for(int i = l; i <= r; i++)
        s1 += arr[i];
    for(int i = l; i <= r; i++)
    {
        
    }

=======
#include <math.h>
#include <stdlib.h>

int max, n;

int solve(int, int, int,  int *);

int main(void)
{
    scanf("%d", &n);
    int *p1 = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &p1[i]);
        if(i == 0) max = p1[0];
    }
    printf("%d", solve(0,n-1, n, p1));
    return 0;
}

int solve(int a, int b, int n, int *p)
{
    int z = 0;
    printf(", %d %d\n", a, b);
    if(b == a)
    {
        z = p[a];   
    }
    else
    {
        z = solve(a, b-1,n, p) + p[n-1];
    }
    if(z > max) max = z;
    if(a == n-1 && b == n-1) return max;
    else if(b < n-1) return z;
    else if(b == n-1) return solve(a+1,n-1,n,p);
>>>>>>> Stashed changes
    return 0;
}