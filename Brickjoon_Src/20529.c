#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T,N,i1,i2;
int comp(char*,char*);
int main(void)
{
    scanf("%d", &T);
    while(T--)
    {
        i1 = -1;
        i2 = 0;
        scanf("%d", &N);
        if(N > 32) 
        {
            printf("0\n");
            continue;
        }
        else
        {
            char** a1 = (char**)malloc(sizeof(char*)*N);
            for(int i = 0; i < N; i++)
            {
                a1[i] = (char*)malloc(sizeof(char)*5);
                scanf("%s", a1[i]);
            }
            for(int i = 0; i < N-2; i++)
            {
                for(int j = i+1; j < N-1; j++)
                {
                    for(int k = j+1; k < N; k++)
                    {
                        i2 = comp(a1[i],a1[j]) + comp(a1[i],a1[k]) + comp(a1[j],a1[k]);
                        i1 = (i1 == -1 ? i2 : min(i2,i1));
                    }
                }
            }
            for(int i = 0; i < N; i++)
                free(a1[i]);
            free(a1);
            printf("%d\n", i1);
        }
    }
    return 0;
}

int comp(char* a1, char* a2)
{
    int r1 = 0;
    for(int i = 0; i < 4; i++)
        if(a1[i] != a2[i]) r1++;
    return r1;
}

// solve