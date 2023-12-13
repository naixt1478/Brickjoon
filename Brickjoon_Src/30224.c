#include <stdio.h>
#include <string.h>
int a,c,d;
int main(void)
{
    char b[30];
    scanf("%s", &b);
    a = atoi(b);
    d = strlen(b);
    for(int i = 0; i < d; i++)
        if(b[i] == '7') c = 1;
    if(c == 0 && a%7 != 0) printf("%d", 0);
    else if(c == 0 && a%7 == 0) printf("%d", 1);
    else if(c == 1 && a%7 != 0) printf("%d", 2);
    else printf("%d", 3);
    return 0;
}