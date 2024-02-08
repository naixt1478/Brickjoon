#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* c1 = (char*)malloc(sizeof(char) * 10000005);
    int b, N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %s", &b, c1);
        int a = strlen(c1);
        int c = 0;
        for(int j = 0; j < a; j++)
        {
            c += c1[j] - '0';
            c %= b - 1;
        }
        printf("%d\n",c);
    }
    free(c1);
    return 0;
}