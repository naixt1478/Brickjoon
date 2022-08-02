#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, k, t, r{0};
	cin >> n >> k;
	stack<int> mod;
	while(n--)
	{
		cin >> t;
		mod.push(t);
	}
	while(k!=0)
	{
		r += k / mod.top();
		k %= mod.top();
		mod.pop();
	}
	cout << r;
}

// solve