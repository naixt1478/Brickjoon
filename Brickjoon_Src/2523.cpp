#include <bits/stdc++.h>
using namespace std;

void s(int a, int b)
{
	while (++a <= b)
	{
		for (int i = 0; i < a; i++)
			cout << '*';
		cout << '\n';
	}
	while (--b > 0)
	{
		for (int i = 0; i < b; i++)
			cout << '*';
		cout << '\n';
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	s(0, n);
}

// solve