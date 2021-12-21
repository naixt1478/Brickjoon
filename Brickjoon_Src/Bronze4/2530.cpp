#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a = (a * 3600) + (b * 60) + c;
    a = a + d;
    a = a % 86400;
    cout << a / 3600 << ' ' << (a % 3600) / 60 << ' ' << (a % 3600) % 60;
}