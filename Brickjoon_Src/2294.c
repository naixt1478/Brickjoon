#define min(a,b) (((a)<(b))?(a):(b))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n,k,a;
    scanf("%d %d", &n, &k);
    int* arr1 = (int*)calloc(k+1, sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        arr1[a] = 1;
        for(int j = a+1; j <= k; j++)
            if(arr1[j - a] != 0)
            {
                if(arr1[j] == 0) arr1[j] = arr1[j-a] + arr1[a];
                else arr1[j] = min(arr1[j], arr1[j - a] + arr1[a]);
            }
    }
    printf("%d", (arr1[k] == 0 ? -1 : arr1[k]));
    return 0;
}