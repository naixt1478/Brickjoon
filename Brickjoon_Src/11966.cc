#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a{1},b{};
    cin >> n;
    for(int i = 0; i < 31; i++)
    {
        if(a == n) b = 1;
        else a *= 2;
    }
    cout << b;
}

// solve