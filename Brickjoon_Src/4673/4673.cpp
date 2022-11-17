#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& vec)
{
	int a(n);
	while(a!=0)
	{
		n += a % 10;
		a /= 10;
	}
	if (n <= 10000 && vec[n] == 0)
	{
		vec[n]++;
		solve(n, vec);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> t(10001);
	for (int i = 1; i <= 10000; i++)
	{
		solve(i, t);
		if (t[i] == 0) cout << i << '\n';
	}
}

// solve