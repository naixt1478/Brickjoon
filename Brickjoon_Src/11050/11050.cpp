#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0) return 1;
    return fact(n - 1) * n;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << fact(n)/(fact(k) * fact(n-k));
}

// solve