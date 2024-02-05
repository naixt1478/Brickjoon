#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
시계 방향 또는 반시계 방향으로 현재 집에서 거리가 
2 이하인 집에만 갈 수 있다.
세 번 연속 같은 방향으로 갈 수 없다.
같은 집을 두 번 연속으로 방문할 수 없다.
*/
int N;
int main(void)
{
    scanf("%d", &N);
    int k = 0,i = 0;
    int* arr1 = (int*)calloc(0, sizeof(int));
        if(N % 3 == 2)
        {
            i = 2;
            k = 1;
            arr1 = realloc(arr1, sizeof(int) * (k + 1));
            arr1[k - 1] = 1;
            arr1[k] = 2;
        }
        else if(N % 3 == 1) i = 1;
        for(int j = 0; j < (N - i)/3; j++)
        {
            printf("%d|\n",j);
            arr1 = realloc(arr1, sizeof(int) * (k + 4));
            k += 3;
            arr1[k - 2] = arr1[k - 3] + 2;
            arr1[k - 1] = arr1[k - 3] + 1;
            if(arr1[k - 3] + 3 == N + 1)
                arr1[k] = 1;
            else
                arr1[k] = arr1[k - 3] + 3;
        }

        if(N % 3 >= 1)
        {
            k += 1;
            arr1 = realloc(arr1, sizeof(int) * (k + 4));
            arr1[k] = 1;
        }
    printf("%d\n",k);
    for(int i = 0; i <= k; i++)
        printf("%d ", arr1[i]);
    return 0;
}