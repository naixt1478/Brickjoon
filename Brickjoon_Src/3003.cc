#include <iostream>
void n(int b)
{
    int a = 0;
    std::cin >> a;
    a = ((-1 * a) + b);
    printf("%d ", a);
}

int main()
{
    n(1),n(1),n(2),n(2),n(2),n(8);
}

// solve