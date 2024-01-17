#include <stdio.h>

int main(void)
{
    int a,b,c,d,sum1=0,sum2=0;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    sum1 = a + d;
    sum2 = b + c;
    if(sum1 > sum2) printf("Persepolis");
    else if(sum1 < sum2) printf("Esteghlal");
    else
    {
        if(b > d) printf("Esteghlal");
        else if(b < d) printf("Persepolis");
        else printf("Penalty");
    }
    return 0;
}