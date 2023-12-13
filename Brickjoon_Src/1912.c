#include <stdio.h>
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

    return 0;
}