#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
	_FASTIOS;
	int N;
	cin >> N;
	vector<vector<int>> vvi1(N, vector<int>(3));
	for(auto& vi1 : vvi1)
	for(auto& i1 : vi1)
	{
		cin >> i1;
	}
	for(int i = 1; i < N; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(j==0)
			{
				vvi1[i][j] += rng::min(vvi1[i-1][1], vvi1[i-1][2]);
			}
			else if(j==1)
			{
				vvi1[i][j] += rng::min(vvi1[i - 1][0], vvi1[i - 1][2]);
			}
			else if(j==2)
			{
				vvi1[i][j] += rng::min(vvi1[i - 1][0], vvi1[i - 1][1]);
			}
		}
	}
	cout << *rng::min_element(vvi1[N - 1]);
}

// solve