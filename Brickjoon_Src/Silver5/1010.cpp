#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define ffx(a) (a < 0 ? 0 : a)
using namespace std;
namespace rng = ranges;
template <typename T>
using v = vector<T>;
v<v<int>> vvi1(31, v<int>(31, -1));

int solve(int n, int k)
{
	if (vvi1[n][k] == -1)
	{
		if (n == k || n == 0)
		{
			vvi1[n][k] = 1;
			return vvi1[n][k];
		}
		vvi1[n][k] = solve(ffx(n-1), ffx(k - 1)) + solve(n, ffx(k - 1));
	}
	return vvi1[n][k];
}

int main()
{
	__fastios;
	int T,a,b;
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		cout << solve(a, b) << '\n';
	}
}

// solve
