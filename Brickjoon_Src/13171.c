#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int64_t mod_exp(int64_t base, int64_t exp, int64_t mod);
int64_t mod_multi(int64_t a, int64_t b, int64_t mod);

int main(void)
{
    int64_t lli1,lli2;
    scanf("%lld %lld", &lli1, &lli2);
    printf("%lld", mod_exp(lli1, lli2, 1000000007));
    return 0;
}

int64_t mod_multi(int64_t a, int64_t b, int64_t mod)
{
    int64_t value = 0;
    a %= mod;
    while(b > 0)
    {
        if(b & 1)
            value = (value + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return value % mod;
}

int64_t mod_exp(int64_t base, int64_t exp, int64_t mod)
{
    int64_t value = 1;
    while(exp > 0)
    {
        if(exp & 1)
            value = mod_multi(value, base, mod);
        base = mod_multi(base, base, mod);
        exp >>= 1;
    }
    return value % mod;
}