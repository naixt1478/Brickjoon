#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b);
int lcm(int a, int b);

int main(void)
{
    int T,lcm1,n,m,a,x,y;
    scanf("%d", &T);
    while(T--)
    {
        a = -1;
        scanf("%d %d %d %d", &m, &n, &x, &y);
        lcm1 = lcm(n,m);
        for(int i = x; i <= lcm1; i+=m)
        {
            if((i % n == 0 ? n : i % n) == y)
            {
                a = i;
                break;
            }
        }
        printf("%d\n",a);
    }
    return 0;
}

int gcd(int a, int b)
{
    while (b != 0) 
    {
    	int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a*b) / gcd(a,b);
}