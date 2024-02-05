#define max(x, y) (((x) > (y)) ? (x) : (y))
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int* pi1; (int*)malloc(sizeof(int) * n);
    int* dp1; (int*)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &pi1[i]);  
        dp1[i] = pi1[i];
    }
    for(int i = 0; i < n; i++)
    {
        dp1[i + 1] = max(pi1[i] + pi1[i + 1], dp1[i + 1]);
        dp1[i + 2] = max(pi1[i], dp1[i + 2]);
        dp1[i + 3] = max(pi1[i] + pi1[i + 1], dp1[i + 3]);
    }
    return 0;
}