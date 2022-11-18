#include <bits/stdc++.h>
using namespace std;

int faci(int n)
{
    if (n == 0) return 1;
    return faci(n-1) * n;
}

int main()
{
    int n;
    cin >> n;
    cout << faci(n);
}

// solve