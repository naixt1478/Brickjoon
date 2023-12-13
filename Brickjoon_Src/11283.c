#include <stdio.h>
#include <locale.h>

char mb[10];
unsigned char a,b,c;

int main(void)
{
    setlocale(LC_ALL, "en_US.UTF-8");
    scanf("%s", mb);
    a = (unsigned)mb[0];
    b = (unsigned)mb[1];
    c = (unsigned)mb[2];
    printf("%d", ((a & 31) << 12) + ((b & 127) << 6) + (c & 127) - 44031);
    return 0;
}
