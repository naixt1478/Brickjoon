#include <stdio.h>

int main()
{
    int N, a=0, b=0;
    char c;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%c", &c);
        if(c == 'D') a++;
        if(c == 'P') b++;
        
        if( abs(a-b) == 2 ) 
        {
            break;
        }
    }
    printf("%d:%d", a, b);
    return 0;
}