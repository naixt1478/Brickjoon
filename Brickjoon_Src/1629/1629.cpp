#include <bits/stdc++.h>
using namespace std;

long long fpw(long long a, long long b, int c)
{
    if (b == 0) return 1;
    long long t = fpw(a, b / 2, c);
    long long r = (t * t) % c;
    if (b % 2 == 0)
        return r;
    return (a * r) % c;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << fpw(a, b, c) % c;
}

// solve