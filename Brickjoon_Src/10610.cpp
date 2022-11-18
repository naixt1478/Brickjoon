#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0);
using namespace std;
namespace rng = ranges;
typedef long long int lli;
constexpr int mod = 30;

int main()
{
	_FASTIOS
	basic_string<char> bsc1;
	int res{};
	cin >> bsc1;
	rng::sort(bsc1, greater<>());
	for(const auto& c : bsc1) res = ((res * 10) + (c - '0')) % mod;
	if (res ^ 0) cout << -1;
	else cout << bsc1;
}

// solve