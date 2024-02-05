#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int a,b,i1,i2,i3;
int main(void)
{
    while(1)
    {
        long long int cnt = 0;
        scanf("%lld", &a);
        if(a == 0) break;
        i1 = a * a;
        for(int i = 1; i <= a; i++)
        {
            if(i1 % i == 0)
            {
                i2 = i1 / i; // c - b
                i3 = i; // c + b
                if((i2 + i3) % 2 == 0 && (i2 - i3) % 2 == 0 && (i2 - i3) / 2 > a)
                    cnt += 1;
            }
        }
        printf("%lld\n", cnt);
    }
    return 0;
}