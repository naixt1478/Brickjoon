#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, b = 0, f = 1, buf;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		buf = b + f;
		b = f;
		f = buf;
	}
	cout << f;
}

// solve 