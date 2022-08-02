#include <bits/stdc++.h>
using namespace std;

int fnum(int n)
{
	if (n < 2) return n;
	return fnum(n - 1) + fnum(n-2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	cin >> n;
	cout << fnum(n);
}

// solve
/*
 * Big O : O^2 very danger not req;
 *
 */