#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int n,i1;
int** ppi2;
int** ppi1;
int solve_bt(int cnt, int i, int j);
int main(void)
{
    scanf("%d", &n);
    ppi1 = (int**)malloc(sizeof(int*) * n);
    ppi2 = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++)
    {
        ppi1[i] = (int*)calloc(2, sizeof(int));
        ppi2[i] = (int*)calloc(n, sizeof(int));
    }
    solve_bt(0, 0, 0);
    printf("%d", i1);
    return 0;
}

int solve_bt(int cnt, int i, int j)
{
    if(cnt == n)
        i1 += 1;
    else
    {
        while(i < n)
        {
            while(j < n)
            {
                int i2 = 1;
                for(int k = 0; k < cnt; k++)
                {
                    if(ppi1[k][0] == i || ppi1[k][1] == j || abs(ppi1[k][0] - i) == abs(ppi1[k][1] - j))
                    {
                        i2 = 0;
                        break;
                    }
                }
                if(i2 == 1)
                {
                    ppi1[cnt][0] = i;
                    ppi1[cnt][1] = j;
                    solve_bt(cnt + 1, i, j + 1);
                }
                j++;
            }
            i++;
            j = 0;
        }
    }
    return 0;
}