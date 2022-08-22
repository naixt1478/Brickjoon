#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template <typename T>
using bs = basic_string<T>;

void solve()
{
	int n;
	cin >> n;
	vector<pair<int, bs<char>>> vp1(n);
	for (auto& [i1, bsc1] : vp1) cin >> bsc1 >> i1;
	rng::sort(vp1, rng::greater());
	cout << vp1[0].second << '\n';
}

int main()
{
	_FASTIOS;
	int T;
	cin >> T;
	while (T--) solve();
}

// solve