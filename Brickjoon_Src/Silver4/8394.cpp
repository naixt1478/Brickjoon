#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
constexpr int mod = 10;

int main()
{
	_FASTIOS;
	int n, a{0}, b{1};
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		rng::swap(a, b);
		b = (a % mod + b % mod) % mod;
	}
	cout << b;
}

// solve