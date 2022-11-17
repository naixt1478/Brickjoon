#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
	__fastios;
	int T,i1, sum1, min1{};
	cin >> T;
	while (T--)
	{
		sum1 = 0, min1 = 100;
		for (int i = 0; i < 7; i++)
		{
			cin >> i1;
			if (i1 % 2 == 0)
			{
				sum1 += i1;
				min1 = rng::min(min1, i1);
			}
		}
		cout << sum1 << ' ' << min1 << '\n';
	}
}

// solve