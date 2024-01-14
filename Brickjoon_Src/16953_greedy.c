#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// for greedy solve
int A,B,c;
int main(void)
{
    scanf("%d %d", &A, &B);
    while(1)
    {
        if(B==A)
        {
            break;
        }
        else if(A>B)
        {
            c = -1;
            break;
        }
        else
        {
            if(B%10 == 1)
            {
                B /= 10;
                c++;
            }
            else if(B%2 == 0)
            {
                B /= 2;
                c++;
            }
            else
            {
                c = -1;
                break;
            }
        }
    }
    printf("%d", (c == -1 ? -1 : c+1));
    return 0;
}