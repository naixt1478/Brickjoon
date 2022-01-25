#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, a, b=0;
	cin >> n;
	while (n--)
	{
		cin >> a;
		if (n < 1)
		{
			b += a;
		}
		else
		{
			b += a - 1;
		}
	}
	cout << b;
}

// solve