#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	long long n, x, y, sqit;
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		sqit = sqrt(y - x);
		cout << sqit * 2 - 1 + ((y - x) - sqit * sqit + sqit - 1) / sqit << '\n';
	}
}

// solve