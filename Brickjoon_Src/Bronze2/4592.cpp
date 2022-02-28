#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, b{}, f{};
    while (cin >> n)
    {
        b = 0;
        if (n==0) break;
        while(n--)
        {
            cin >> f;
            if (b!=f) cout << f << ' ';
            b = f;
        }
        cout << "$\n";
    }
}

// solve