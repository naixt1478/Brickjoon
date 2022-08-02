#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
	__fastios;
	int N, sum1{}, now1{};
	cin >> N;
	vector<int> vi1(N);
	for (auto& i1 : vi1) cin >> i1;
	for (int i = N-1; i >= 0; i--)
	{
		if (i == N-1) now1 = vi1[i];
		else
		{
			if (vi1[i] >= now1)
			{
				sum1 += vi1[i] - now1 + 1;
				vi1[i] = now1 - 1;
			}
			now1 = vi1[i];
		}
	}
	cout << sum1;
}
// top down + greedy solving
//
// solve greddy? DP?