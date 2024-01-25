#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

long long int** mpow(long long int** m1, long long int n, long long int n2, long long int s1);
void mmulti(long long int** dest, long long int** L, long long int** R, long long int Ly, long long int Lx, long long int Ry, long long int Rx);

const long long int mod = 1000000007;

int main(void)
{
    long long int** m1 = malloc(sizeof(long long int*) * 2);
    long long int** R = malloc(sizeof(long long int*) * 2);
    long long int** result = malloc(sizeof(long long int*) * 2);
    for(long long int i = 0; i < 2; i++) 
    {
        result[i] = (long long int*)malloc(sizeof(long long int));
        R[i] = (long long int*)calloc(1,sizeof(long long int));
        m1[i] = (long long int*)calloc(2, sizeof(long long int));
    }
    R[0][0] = 1;
    R[1][0] = 0;
    m1[0][0] = 1;
    m1[0][1] = 1;
    m1[1][0] = 1;
    m1[1][1] = 0;
    long long int n;
    scanf("%lld", &n);
    if(n == 1) printf("1");
    else
    {
        long long int** arr1 = mpow(m1, n - 1, n - 1, 2);
        mmulti(result, arr1, R, 2, 2, 2, 1);
        printf("%lld", result[0][0]);
    }
    return 0;
}

void mmulti(long long int** dest, long long int** L, long long int** R, long long int Ly, long long int Lx, long long int Ry, long long int Rx)
{
    for(long long int i = 0; i < Ly; i++)
    {
        long long int* t1 = (long long int*)calloc(Rx, sizeof(long long int));
        for(long long int j = 0; j < Rx; j++)
        {
            long long int i1 = 0;
            for(long long int k = 0; k < Ry; k++)
                i1 += ((L[i][k] % mod) * (R[k][j] % mod)) % mod;
            t1[j] = i1 % mod;
        }
        memcpy(dest[i], t1, sizeof(long long int) * Rx);
        free(t1);
    }
}

long long int** mpow(long long int** m1, long long int n, long long int n2, long long int s1)
{
    long long int** r1 = (long long int**)malloc(sizeof(long long int*) * s1);
    for(long long int i = 0; i < s1; i++) r1[i] = (long long int*)calloc(s1, sizeof(long long int));
    if(n == 1)
    {
        for(long long int i = 0; i < s1; i++)
            for(long long int j = 0; j < s1; j++) r1[i][j] = m1[i][j];
        return r1;
    }
    else if(n == 0)
    {
        for(long long int i = 0; i < s1; i++)
            r1[i][i] = 1;
        return r1;
    }
    long long int** n1 = mpow(m1, n/2, n2, s1);
    mmulti(r1,n1,n1,s1,s1,s1,s1);
    for(int i = 0; i < s1; i++) free(n1[i]);
    free(n1);
    if(n%2 != 0) mmulti(r1,r1,m1,s1,s1,s1,s1);
    return r1;
}