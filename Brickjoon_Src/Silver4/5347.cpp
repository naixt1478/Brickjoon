#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	int t, a, b;
	cin >> t;
	_FASTIOS;
	while(t--)
	{
		cin >> a >> b;
		cout << lcm(a, b) << '\n';
	}
}

// solve
// + TODO : again ~