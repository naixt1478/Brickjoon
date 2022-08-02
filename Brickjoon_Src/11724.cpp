#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
using vi = vector<int>;

void BFS_edit1(vector<vi>& vvi1,vi& checked1,int snode)
{
	int node;
	queue<int> bfs_queue1;
	bfs_queue1.emplace(snode);
	checked1[snode] = 1;
	while(bfs_queue1.empty() != 1)
	{
		node = bfs_queue1.front();
		bfs_queue1.pop();
		for(auto& sn1 : vvi1[node])
		{
			if(checked1[sn1] == 0)
			{
				bfs_queue1.push(sn1);
				checked1[sn1] = 1;
			}
		}
	}
}

int main()
{
	__fastios;
	int N, M, a, b, i1{};
	cin >> N >> M;
	vector<vi> vvi1 (N+1);
	vi vi1(N + 1);
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		vvi1[a].emplace_back(b);
		vvi1[b].emplace_back(a);
	}
	for(int i = 1; i <= N; i++)
	{
		if(vi1[i] == 0)
		{
			i1++;
			BFS_edit1(vvi1, vi1, i);
		}
	}
	cout << i1;
}

// solve