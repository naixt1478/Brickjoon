#include <stdio.h>
int n,a,b,c;

int main(void)
{
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d %d", &a, &b, &c);
        printf("Data set: %d %d %d\n", a, b, c);
        for(int i = 0; i < c; i++)
        {
            a = a / 2;
            b = b / 2;
        }
        printf("%d %d\n\n", a, b);
    }
    return 0;
}