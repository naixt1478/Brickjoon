#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template <typename T>
using V = vector<T>;

int main()
{
	__fastios;
	long long int T, a{}, sum1{}, XOR1{};
	cin >> T;
	while (T--)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> a;
			sum1 += a;
			XOR1 ^= a;
		}
		else if (a == 2)
		{
			cin >> a;
			sum1 -= a;
			XOR1 ^= a;
		}
		else if (a == 3) cout << sum1 << '\n';
		else if (a == 4) cout << XOR1 << '\n';
	}
}

// solve
