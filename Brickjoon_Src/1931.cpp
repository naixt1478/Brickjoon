#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, a, b, r{0};
	cin >> n;
	vector<pair <int, int>> time;
	while(n--)
	{
		cin >> b >> a;
		time.emplace_back(pair(a, b));
	}
	ranges::sort(time);
	b = 0;
	for (auto& [s, f] : time)
	{
		if (b <= f)
		{
			r++;
			b = s;
		}
	}
	cout << r;
}

// solve