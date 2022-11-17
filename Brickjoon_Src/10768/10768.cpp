#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int m, d;
    cin >> m >> d;
    cout << (m*31 + d == 80 ? "Special" : (m*31 + d > 80 ? "After" : "Before"));
}

// solve