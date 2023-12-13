#include <stdio.h>
int a,b,c,d,m,n,s;

int main(void)
{
    scanf("%d %d %d %d", &a, &b, &c, &d);
    m = b-a;
    n = d-c;
    while(m!=n)
    {
        if(m>n)
            n += d;
        else
            m += b;
    }
    printf("%d", n);
    return 0;
}