#include <stdio.h>
#include <stdlib.h>
int n, x, y, sum, tmp;

int s1(int a,int b, int **arr);

int main(void)
{
    scanf("%d", &n);
    int **arr2 = calloc(101, sizeof(int*));
    for(int i = 0; i <= 100; i++)
        arr2[i] = (int *)calloc(101,sizeof(int)); 
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        for(int j = x + 1; j <= x + 10; j++)
        {
            for(int k = y + 1; k <= y + 10; k++)
                arr2[j][k]++;
        }
    }
    for(int i = 0; i <= 100; i++)
    {
        for(int j = 0; j <= 100; j++)
        {
            tmp = arr2[j][i];
            if(tmp >= 1) sum += 1;
        }
    }
    printf("%d", sum);
    // free() phase
    return 0;
}