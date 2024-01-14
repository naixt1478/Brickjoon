#include <stdio.h>
#include <string.h>

int N,check;

int main(void)
{
    char c1[7][100];
    strcpy(c1[0], "Never gonna give you up");
    strcpy(c1[1], "Never gonna let you down");
    strcpy(c1[2], "Never gonna run around and desert you");
    strcpy(c1[3], "Never gonna make you cry");
    strcpy(c1[4], "Never gonna say goodbye");
    strcpy(c1[5], "Never gonna tell a lie and hurt you");
    strcpy(c1[6], "Never gonna stop");
    char c2[100];
    check = 0;
    fgets(c2, 100, stdin);
    if(c2[strlen(c2)-1] == '\n')
        c2[strlen(c2)-1] = '\0';
    sscanf(c2, "%d", &N);
    for(int i = 0; i < N; i++)
    {
        fgets(c2, 100, stdin);
        if(c2[strlen(c2)-1] == '\n')
            c2[strlen(c2)-1] = '\0';
        for(int j = 0; j < 7; j++)
        {
            if(strcmp(c2, c1[j]) == 0)
                check += 1;
        }
    }
    if(check == N)
        printf("No");
    else
        printf("Yes");
    return 0;
}