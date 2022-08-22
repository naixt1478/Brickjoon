#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
using namespace std;
namespace rng = ranges;
using lli = long long int;
using bsc = basic_string<char>;
using pii = pair<int, int>;

int main()
{
	int N, K;
	_FASTIOS;
	cin >> N >> K;
	vector<int> check(100001);
	queue<pii> BFS_in;
	BFS_in.emplace(N, 0);
	check[N] = true;
	while(BFS_in.empty()!=1)
	{
		auto [N2, cnt] = BFS_in.front();
		BFS_in.pop();
		vector<int> comp = { N2 + 1, N2 - 1, N2 * 2 };
		if(N2 == K)
		{
			cout << cnt;
			break;
		}
		for(auto& Ci : comp)
		{
			if (0 <= Ci && Ci <= 100000 && check[Ci] == 0)
			{
				BFS_in.emplace(Ci, cnt + 1);
				check[Ci] = true;
			}
		}
	}
}

// solve
