#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

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
	int T,a,b;
	long long c;
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		c = fpw(a, b, 10);
		cout << (c == 0 ? 10 : c) << '\n';
	}
}

// solve