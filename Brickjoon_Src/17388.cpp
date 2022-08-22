#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d, a, b, c;
    cin >> a >> b >> c;
    d = min({a, b, c});
    if (a + b + c >= 100) cout << "OK";
    else
        cout << (a == d ? "Soongsil" : (b == d ? "Korea" : "Hanyang"));
}

// solve