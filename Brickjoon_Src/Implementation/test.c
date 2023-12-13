#include <stdio.h>
#include <stdlib.h>

void test1(int*);
int main(void)
{
    int a = 1;
    int* b = &a;
    printf("before a : %d\n",a);
    test1(b);
    printf("after a : %d\n",a);
    return 0;
}
void test1(int* p1)
{
    printf("in function before a : %d\n", *p1);
    *p1 = 0;
    printf("in function after a : %d\n", *p1);
}