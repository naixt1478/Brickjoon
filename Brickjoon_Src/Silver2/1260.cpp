#include <bits/stdc++.h>
using namespace std;
namespace rng = ranges;
typedef vector<int> vi;

void DFS(int snode,vector<vi>& Amatrix,vi& checked)
{
	if (checked[snode]) return;
	cout << snode << ' ';
	checked[snode] = true;
	for(auto& node : Amatrix[snode])
	{
		if(checked[node] == false) DFS(node, Amatrix, checked);
	}
}

void BFS(int snode,vector<vi>& Amatrix,vi& checked)
{
	int queue_node;
	queue<int> BFS_queue1;
	BFS_queue1.push(snode);
	checked[snode] = true;
	while(BFS_queue1.empty() != 1)
	{
		queue_node = BFS_queue1.front();
		cout << queue_node << ' ';
		BFS_queue1.pop();
		for(auto& node : Amatrix[queue_node])
		{
			if(checked[node] == false)
			{
				BFS_queue1.push(node);
				checked[node] = true;
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int N, M, V, t, t2;
	cin >> N >> M >> V;
	vector<vi> AM1(N+1);
	vi DFS1(N+1), BFS1(N+1);
	for(int i = 0; i < M; i++)
	{
		cin >> t >> t2;
		AM1[t].emplace_back(t2);
		rng::sort(AM1[t]);
		AM1[t2].emplace_back(t);
		rng::sort(AM1[t2]);
	}
	DFS(V, AM1, DFS1);
	cout << '\n';
	BFS(V, AM1, BFS1);
}

// solve