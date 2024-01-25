#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int n,i1;
int pi1[16];
void solve_bt(int i);
int main(void)
{
    scanf("%d", &n);
    solve_bt(0);
    printf("%d", i1);
    return 0;
}

void solve_bt(int y)
{
    for(pi1[y] = 0; pi1[y] < n; pi1[y]++)
    {
        int i2 = 1;
        for(int k = 0; k < y; k++)
        {
            if(pi1[k] == pi1[y] || abs(pi1[k] - pi1[y]) == abs(k - y))
            {
                i2 = 0;
                break;
            }
        }
        if(i2)
        {
            if(y == n - 1) 
            {
                i1 += 1;
                return;
            }
            solve_bt(y + 1);
        }
    }
}