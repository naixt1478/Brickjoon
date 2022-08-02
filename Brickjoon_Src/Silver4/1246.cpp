#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	lli N, M, a{}, b{}, i{};
	cin >> N >> M;
	vector<lli> num(M);
	for(auto& i : num) cin >> i;
	ranges::sort(num, greater<>());
	for(auto& n : num)
	{
		if (++i > N) break;
		else if (n * i > a)
		{
			b = n;
			a = b * i;
		}
	}
	cout << b << ' ' << a;
}

// solve