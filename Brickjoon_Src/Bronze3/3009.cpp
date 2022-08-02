#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr);
	int t, n, x=0, y=0;
	while (cin >> t >> n)
	{
		x^=t;
		y^=n;
	}
	cout << x << ' ' << y;
}

// solve