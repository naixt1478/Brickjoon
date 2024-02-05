#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int M;
int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("TestInput.txt", "r" , stdin);
        freopen("TestOutput.txt", "w" , stdout);
    #endif
    setlocale(LC_ALL, "en_US.UTF-8");
    char c1[3002], c2[3002];
    scanf("%s", c1);
    scanf("%s", c2);
    int a = strlen(c1) / 3;
    int b = strlen(c2) / 3;
    int** klcs1 = (int**)malloc(sizeof(int*) * (a + 1));
    for(int i = 0; i <= a; i++)
        klcs1[i] = (int*)calloc(b + 1, sizeof(int));
    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            if
            (
                c1[(i - 1) * 3] == c2[(j - 1) * 3] &&
                c1[(i - 1) * 3 + 1] == c2[(j - 1) * 3 + 1] &&
                c1[(i - 1) * 3 + 2] == c2[(j - 1) * 3 + 2]
            )
            {
                klcs1[i][j] = klcs1[i - 1][j - 1] + 1;
                if(klcs1[i][j] > M) M = klcs1[i][j];
            }
            else
            {
                if(klcs1[i - 1][j] > klcs1[i][j - 1]) klcs1[i][j] = klcs1[i - 1][j];
                else klcs1[i][j] = klcs1[i][j - 1];
            }
        }
    }
    printf("%d", M);
    for(int i = 0; i <= a; i++) free(klcs1[i]);
    free(klcs1);
    return 0;
}