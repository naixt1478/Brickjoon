#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		if (i > n)
		{
			for (int j = 0; j < i - n; j++) cout << ' ';
			for (int j = 0; j < n - i % n; j++) cout << '*';
		}
		else
		{
			for (int j = 0; j < n - i; j++) cout << ' ';
			for (int j = 0; j < i; j++) cout << '*';
		}
		cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	cin >> n;
	solve(n);
}

// solve