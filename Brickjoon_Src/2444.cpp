#include <bits/stdc++.h>
using namespace std;

void solve(int a,int b)
{
	for (int i = 0; i < b - 1-a; i++) cout << ' ';
	for (int i = 0; i <= a*2; i++) cout << '*';
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		solve(i, n);
	}
	for (int i = n - 2; i >= 0; i--)
	{
		solve(i, n);
	}
}

// solve