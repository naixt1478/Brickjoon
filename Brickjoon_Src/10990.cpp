#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

void solve(int a, int b)
{
	for (int i = 0; i < a; i++) cout << ' ';
	cout << '*';
	if (a == 0 && b == -1) return;
	else if (b == -1)
	{
		cout << '\n';
		return solve(a - 1, b + 2); 
	}
	for (int i = 0; i < b; i++) cout << ' ';
	cout << '*';
	if (a == 0) return;
	else
	{
		cout << '\n';
		return solve(a - 1, b + 2);
	}
}

int main()
{
	_FASTIOS;
	int n;
	cin >> n;
	solve(n-1, -1);
}

// solve