#include <bits/stdc++.h>
using namespace std;

void s(int a, int b)
{
	for (int i = 0; i < a; i++)
		cout << '*';
	for (int i = 0; i < (b - a) * 2; i++)
		cout << ' ';
	for (int i = 0; i < a; i++)
		cout << '*';
	cout << '\n';
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		s(i, n);
	for (int i = n - 1; i > 0; i--)
		s(i, n);
}