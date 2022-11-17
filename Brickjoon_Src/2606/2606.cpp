#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
using namespace std;
namespace rng = ranges;
using lli = long long int;
using bsc = basic_string<char>;
using vi = vector<int>;

int BFS(int snode,vector<vi>& graph1,vi& ch)
{
	int cnt{};
	queue<int> BFS_in;
	BFS_in.emplace(snode);
	ch[snode] = true;
	while(!BFS_in.empty())
	{
		auto cidx = BFS_in.front();
		BFS_in.pop();
		for(auto& node : graph1[cidx])
		{
			if(!ch[node])
			{
				BFS_in.emplace(node);
				ch[node] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	_FASTIOS;
	int C,T,a,b;
	cin >> C >> T;
	vector<vi> xyv1(C + 1);
	vi check(C + 1);
	while(T--)
	{
		cin >> a >> b;
		xyv1[a].emplace_back(b);
		xyv1[b].emplace_back(a);
		rng::sort(xyv1[a]);
		rng::sort(xyv1[b]);
	}
	cout << BFS(1, xyv1, check);
}

// solve