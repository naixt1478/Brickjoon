#include <stdio.h>
int N, m, a, S[9] = {0, };

void rs1();

int main(void)
{
    rs1();
    scanf("%d", &N);
    while(N != -1)
    {
        a = N % 10;
        if(a == 9 || a == 6)
            a = 6;
        S[a]--;
        if(S[a] < 0) rs1();
        if(N / 10 == 0) N = -1;
        else N = N / 10;
    }
    printf("%d", m);
    return 0;
}

void rs1()
{
    m += 1;
    for(int i = 0; i < 9; i++)
    {
        if(i == 6) S[i] += 2;
        else S[i] += 1;
    } 
}
