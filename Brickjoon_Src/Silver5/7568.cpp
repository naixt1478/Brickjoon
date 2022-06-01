#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,t,a,b;
	vector<pair<int, int>> v1;
	cin >> t;
	n = t;
	while(n--)
	{
		cin >> a >> b;
		v1.emplace_back(pair(a, b));
	}
	for(auto& [b, c] : v1)
	{
		a = 1;
		for(auto& [f,s] : v1) if (b < f && c < s) a++;
		cout << a << ' ';
	}
}

// solve