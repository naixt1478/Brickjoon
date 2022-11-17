#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	_FASTIOS;
	int n, A{100}, B{ 100 },a,b;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		if (a > b) B -= a;
		else if (a < b) A -= b;
	}
	cout << A << '\n' << B;
}

// solve