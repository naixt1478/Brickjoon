#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
int N, M;

void s1(vector<vector<int>>& vvi1,int x,int y,int& max1)
{
	int i1;
	if(0 <= x && x+1 < N && 0 <= y && y+1 < M)
	{
		i1 = vvi1[x][y] + vvi1[x + 1][y] + vvi1[x][y + 1] + vvi1[x + 1][y + 1];
		if (i1 > max1) max1 = i1;
	}
}

int main()
{
	__fastios;
	int max1{};
	cin >> N >> M;
	vector<vector<int>> vvi1(N, vector<int>(M));
	for (auto& vi1 : vvi1)
		for (auto& i1 : vi1) cin >> i1;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			s1(vvi1, i, j, max1);
		}
	}
}