#include <stdio.h>

int main()
{
    int T,S;
    scanf("%d %d", &T, &S);
    if(12<=T && T<=16 && S == 0)
    {
        printf("320");
    }
    else
    {
        printf("280");
    }
    return 0;
}