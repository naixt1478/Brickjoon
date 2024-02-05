#define max(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N, M ;
    scanf("%d", &N);
    int* pi1 = (int*)calloc(N, sizeof(int));
    int* dp1 = (int*)calloc(N, sizeof(int));
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &pi1[i]);
        dp1[i] = pi1[i];
        if(i == 0) M = dp1[i];
        for(int j = 0; j < i; j++)
        {
            if(pi1[j] < pi1[i])
            {
                dp1[i] = max(dp1[i], dp1[j] + pi1[i]);
                if(dp1[i] > M) M = dp1[i];
            }
        }
    }
    printf("%d", M);
    free(pi1);
    free(dp1);
    return 0;
}