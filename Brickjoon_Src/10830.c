#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef long long int lli;

lli** mpow(lli** m1, lli n, lli n2, lli s1);
void mmulti(lli** dest, lli** L, lli** R, lli Ly, lli Lx, lli Ry, lli Rx);

const lli mod = 1000;
int main(void)
{
    lli n,b;
    scanf("%lld %lld", &n, &b);
    lli** m1 = (lli**)malloc(sizeof(lli*) * n);
    for(lli i = 0; i < n; i++)
    {
        m1[i] = (lli*)calloc(n, sizeof(lli));
        for(lli j = 0; j < n; j++)
            scanf("%lld", &m1[i][j]);
    }
    lli** arr1 = mpow(m1, b, b, n);
    for(lli i = 0; i < n; i++)
    {
        for(lli j = 0; j < n; j++)
            printf("%lld ",arr1[i][j]);
        printf("\n");
    }
    return 0;
}

void mmulti(lli** dest, lli** L, lli** R, lli Ly, lli Lx, lli Ry, lli Rx)
{
    for(lli i = 0; i < Ly; i++)
    {
        lli* t1 = (lli*)calloc(Rx, sizeof(lli));
        for(lli j = 0; j < Rx; j++)
        {
            lli i1 = 0;
            for(lli k = 0; k < Ry; k++)
                i1 += ((L[i][k] % mod) * (R[k][j] % mod)) % mod;
            t1[j] = i1 % mod;
        }
        memcpy(dest[i], t1, sizeof(lli) * Rx);
        free(t1);
    }
}

lli** mpow(lli** m1, lli n, lli n2, lli s1)
{
    lli** r1 = (lli**)malloc(sizeof(lli*) * s1);
    for(lli i = 0; i < s1; i++) r1[i] = (lli*)calloc(s1, sizeof(lli));
    if(n == 1)
    {
        for(lli i = 0; i < s1; i++)
            for(lli j = 0; j < s1; j++) r1[i][j] = m1[i][j] % mod;
        return r1;
    }
    else if(n == 0)
    {
        for(lli i = 0; i < s1; i++)
            r1[i][i] = 1;
        return r1;
    }
    lli** n1 = mpow(m1, n/2, n2, s1);
    mmulti(r1,n1,n1,s1,s1,s1,s1);
    for(int i = 0; i < s1; i++) free(n1[i]);
    free(n1);
    if(n%2 != 0) mmulti(r1,r1,m1,s1,s1,s1,s1);
    return r1;
}