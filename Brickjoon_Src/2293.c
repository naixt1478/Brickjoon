#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n,k,a;
    scanf("%d %d", &n, &k);
    int* arr1 = (int*)calloc((k+1),sizeof(int));
    arr1[0] = 1;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        for(int j = a; j <= k; j++)
        {
            // a + dp[j-a] | 1 , (1) + 1, (1 + 1) + 1 | 0, 0 , 2 + 0, 2 + (none) = 0, 2 + 2(1)
            arr1[j] = arr1[j-a] + arr1[j];
        }
    }
    printf("%d", arr1[k]);
    return 0;
}