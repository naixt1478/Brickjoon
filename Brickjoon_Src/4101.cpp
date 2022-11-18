#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int a, b;
    while (cin >> a >> b)
    {
        if (!a && !b) break;
        else if (a > b) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}

// solve