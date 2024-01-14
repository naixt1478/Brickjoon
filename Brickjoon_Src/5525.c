#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N,M,i1,a,b,s;
int main(void)
{
    scanf("%d", &N);
    scanf("%d", &M);
    char* arr2 = (char*)malloc(sizeof(char)*(M+1));
    scanf("%s", arr2);
    b = N*2+1;
    for(int i = 0; i < M; i++)
    {
        if(arr2[i] == 'I')
        {
            if(s % 2 == 0)
            {
                s++;
                if(s == b) 
                {
                    b += 2;
                    i1++;
                }
            }
            else
            {
                s = 1;
                b = N*2+1;
            }
        }
        else
        {
            if(s % 2 == 0)
            {
                s = 0;
                b = N*2+1;
            }
            else
                s++;
        }
    }
    printf("%d", i1);
    free(arr2);
    arr2 = NULL;
    return 0;
}

// solve