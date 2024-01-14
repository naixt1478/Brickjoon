#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
#include <stdio.h>
#include <stdlib.h>

int N,m;
int main(void)
{
    scanf("%d", &N);
    int* arr1 = (int*)calloc(N+1,sizeof(int));
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j*j <= i; j++)
        {
            arr1[i] = (arr1[i] == 0 ? arr1[i - j*j] + 1 : min(arr1[i - j*j] + 1,arr1[i]));
        }
    }
    printf("%d", arr1[N]);
}
/*
i - 1, i - 4, i - 9 , ...

i = 1
1 + 0
count : 1
arr 1 = 1
|define|

arr1 1 ~ N not defined

i = 2
제곱수 <= 2
제곱수 : 1,
1*1 + 1
arr1[1] + arr1[1]
count : 2
arr 2 = 2
|define|

arr 2 ~ N not defined

~repeat~

제곱수 <= 4
제곱수 : 1,4
1 + 3
4 + 0

여러개의 제곱수가 있으면 가장 최소의 제곱수 경우를 찾는다.
|arr1[1](제곱수) = {상수 1}| + arr1[3](define 3)
count : 4
A
|arr1[4](제곱수) = {상수 1}| + arr1[0](define 0 because 0 is not counting)
count : 1
B
arr1[4] = min(A,B){1로 정의}
|define|

arr 4 ~ N not defined
repeat 
N 값에 도달할 수 있음
*/