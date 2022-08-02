#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
using namespace std;
namespace rng = ranges;
typedef long long int lli;
constexpr lli mod = 1000000009;
vector<int> memo = { 0,1,2,4 };

lli solve(int n)
{
	const int nsize = memo.size();
	if (n <= nsize - 1) return memo[n];
	else for (int i = nsize - 1; i < n; i++) memo.emplace_back((memo[i] % mod + memo[i - 1] % mod + memo[i - 2] % mod) % mod); // int % lli convert
	return memo[n];
}

int main()
{
	_FASTIOS;
	int T, F;
	cin >> T;
	while (T--)
	{
		cin >> F;
		cout << solve(F) << '\n';
	}
}

// solve