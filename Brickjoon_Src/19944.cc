#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    cout << (m <= 2 ? "NEWBIE!" : (m <= n ? "OLDBIE!" : "TLE!"));
}

// solve