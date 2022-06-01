#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
	_FASTIOS;
	int N, M, a{ 1000 }, b{ 1000 }, t, t2, sum{};
	cin >> N >> M;
	while (M--)
	{
		cin >> t >> t2;
		if (t < a) a = t;
		if (t2 < b) b = t2;
	}
	while (N != 0)
	{
		if (N / 6 > 0)
		{
			sum += rng::min(a, b * 6);
			N -= 6;
		}
		else
		{
			sum += rng::min(a, b * N);
			N = 0;
		}
	}
	cout << sum;
}

// solve
