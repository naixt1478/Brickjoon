#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int n;

long long int solve();
int main(void)
{
    scanf("%lld", &n);
    printf("%lld", solve());
    return 0;
}

long long int solve()
{
    long long int a = n;
    long long int b = n;
    for(long long int p = 2; p * p <= a; p++)
    {
        if(a % p == 0) b = (b / p) * (p - 1);
        while(a % p == 0) a /= p;  
    }
    if(a > 1)
        b = (b / a) * (a - 1);
    return b;
}