#include <bits/stdc++.h>
using namespace std;

void s(int a, int b)
{
	int i(a);
	while (i--)
		cout << ' ';
	for (int j = 1; j < (b - a) * 2; j++)
		cout << '*';
	cout << '\n';
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		s(i, n);
}

// solve