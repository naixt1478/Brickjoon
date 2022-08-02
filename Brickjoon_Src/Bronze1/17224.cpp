#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, l, k, a, b, r{};
	vector<int> result;
	cin >> n >> l >> k;
	result.reserve(n);
	while(n--)
	{
		cin >> a >> b;
		if (b <= l) result.emplace_back(140);
		else if (a <= l) result.emplace_back(100);
		else result.emplace_back(0);
	}
	ranges::sort(result, greater<>());
	for(int& t : result)
	{
		if (k-- < 1) break;
		r += t;
	}
	cout << r;
}

// solve