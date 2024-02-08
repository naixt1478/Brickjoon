#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
시계 방향 또는 반시계 방향으로 현재 집에서 거리가 
2 이하인 집에만 갈 수 있다.
세 번 연속 같은 방향으로 갈 수 없다.
같은 집을 두 번 연속으로 방문할 수 없다.
*/

int N,k;
int main(void)
{
    scanf("%d", &N);
    printf("%d\n", N);
    printf("1 ");
    k = 1;
    if(N % 3 == 2)
    {
        printf("2 ");
        k = 2;
    }
    for(int j = 0; j < N/3; j++)
    {
        int a = k;
        printf("%d %d ", a + 2, a + 1);
        if(N % 3 == 0 && j + 1 == N/3)
            printf("1");
        else
        {
            printf("%d ", a + 3);
            k = a + 3;
        }
    }
    if(N % 3 >= 1)
        printf("1");
    return 0;
}