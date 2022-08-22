#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	__fastios;
	int T, N, t, sum1{};
	cin >> T;
	while (T--)
	{
		sum1 = 0;
		cin >> N;
		while (N--)
		{
			cin >> t;
			sum1 += t;
		}
		cout << sum1 << '\n';
	}
}

// solve