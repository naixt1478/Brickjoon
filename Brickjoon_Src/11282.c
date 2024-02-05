#include <stdio.h>
#include <locale.h>
int N;
char mb[] = "abc";
unsigned char a,b,c;

int main(void)
{
    //freopen("TestInput.txt", "r" , stdin);
    //freopen("TestOutput.txt", "w" , stdout);
    setlocale(LC_ALL, "en_US.UTF-8");
    scanf("%d", &N);
    N += 44031;
    a = (((N&61440) >> 12)|224);
    b = (((N&4032) >> 6)|128);
    c = (((N&63))|128);
    mb[0] = a,mb[1] = b,mb[2] = c;
    printf("%s\n", mb);
    return 0;
}
