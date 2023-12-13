#include <stdio.h>
long long int a,b,c,d,e,f,x,y;
long long int U,D;

int main(void)
{
    scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
    U = a, D = d;
    if(a == 0)
    {
        y = c/b;
        x = (f-e*y)/d;
    }
    else if(d == 0)
    {
        y = f/e;
        x = (c-b*y)/a;
    }
    else if(b == 0)
    {
        x = c/a;
        y = (f-d*x)/e;
    }
    else if(e == 0)
    {
        x = f/d;
        y = (c-a*x)/b;
    }
    else
    {
        y = (c*D-f*U) / (b*D-e*U);
        x = (c - b*y) / a;
    }
    printf("%lld %lld", x, y);
    return 0;
}