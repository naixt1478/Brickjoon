#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    double a, b, c;
    cin >> a >> b >> c;
    cout << int(max((a/b)*c, a*(b/c)));
}

// solve