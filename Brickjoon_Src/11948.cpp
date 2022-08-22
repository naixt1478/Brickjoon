#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n[4],t[2];
	for (int i(0); i < 4; i++)
	{
		cin >> n[i];
	}
	for (int i(0); i < 2; i++)
	{
		cin >> t[i];
	}
	sort(n, n + 4);
	cout << n[3] + n[2] + n[1] + max(t[0], t[1]);
}

// solve