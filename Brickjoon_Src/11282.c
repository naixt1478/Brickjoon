#include <stdio.h>
#include <locale.h>
#include <wchar.h>
int N;
char mb[] = "abc";
wchar_t wc;
unsigned char a,b,c;

int main(void)
{
    setlocale(LC_ALL, "en_US.UTF-8");
    scanf("%d", &N);
    N += 44031;
    a = (((N&61440) >> 12)|224);
    b = (((N&4032) >> 6)|128);
    c = (((N&63))|128);
    mb[0] = a,mb[1] = b,mb[2] = c;
    printf("%x %x %x\n", a, b, c);
    wprintf(L"%lc", wc);
    return 0;
}
