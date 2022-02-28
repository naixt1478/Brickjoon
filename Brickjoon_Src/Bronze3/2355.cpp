#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	lli a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	cout << (a + b) * (b - a + 1) / 2;
}

// solve