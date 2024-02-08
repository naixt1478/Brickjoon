#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int64_t mod_exp(int64_t base, int64_t exp, int64_t mod);
int64_t mod_multi(int64_t a, int64_t b, int64_t mod);

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

// 1 : 1 2^0
// 2 : 1 f(1) -> 2 2^1
// 3 : 1 f(1) f(2) -> 4 2^2
// 4 : 1 f(1) f(2) f(3) -> 8 2^3
// 5 : 1 f(1) f(2) f(3) f(4) -> 16 2^4

int main()
{
    char ans[] = "rgjgmbuyhbfcx";
    for (int i = 0; i < 13; i++)
        ans[i] ^= mod_exp(2, 12 + i * i * i, 13);
    puts(ans);
}