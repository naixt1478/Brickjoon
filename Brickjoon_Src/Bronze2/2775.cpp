#include <bits/stdc++.h>
using namespace std;

int solve(int k, int n, int a = 0)
{
	if (k == 0) return n;
	for (int i = 1; i <= n; i++)
	{
		a += solve(k - 1, i);
	}
	return a;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t,k,n;
	cin >> t;
	while (t--)
	{
		cin >> k >> n;
		cout << solve(k, n) << '\n';
	}
}

// solve
