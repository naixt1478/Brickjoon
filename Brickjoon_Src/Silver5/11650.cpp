#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,x,y;
	vector<pair <int, int>> xy;
	cin >> n;
	while(n--)
	{
		cin >> x >> y;
		xy.emplace_back(pair<int, int>(x, y));
	}
	ranges::sort(xy);
	for(const auto& [f,s] : xy)
	{
		cout << f << ' ' << s << '\n';
	}
}

// solve