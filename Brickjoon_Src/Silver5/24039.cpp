#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, b(2), a(3), i(3), d(0);
    cin >> n;
    while (n >= b * a)
    {
        i++;
        d = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                d++;
                break;
            }
        }
        if (!d)
        {
            b = a;
            a = i;
        }
    }
    cout << b * a;
}

// solve