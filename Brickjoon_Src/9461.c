#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T,N;
int main(void)
{
    long long int arr1[101] = {0,1,1,1,2,2,};
    for(int i = 6; i < 101; i++)
        arr1[i] = arr1[i-1] + arr1[i-5];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        printf("%lld\n", arr1[N]);
    }
    return 0;
}