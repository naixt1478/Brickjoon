#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0);
using namespace std;
namespace rng = ranges;
using lli = long long int;
using bsc = basic_string<char>;
int N, M;

vector<pair<int, int>> comp = {pair(1, 0), pair(0, 1), pair(-1, 0), pair(0, -1)};

struct info
{
	int x, y, cnt;
};

int BFS(int snode, int snode2, vector<bsc>& AM1)
{
	int mcnt{1000000};
	queue<info> BFS_queue1;
	BFS_queue1.emplace(snode, snode2, 1);
	AM1[snode][snode2] = '0';
	while (BFS_queue1.empty() != 1)
	{
		auto [x, y, cnt] = BFS_queue1.front();
		BFS_queue1.pop();
		for (auto& [dx,dy] : comp)
		{
			if (x == N - 1 && y == M - 1) mcnt = rng::min(cnt, mcnt);
			else if (0 <= (x + dx) && (x + dx) < N && 0 <= (y + dy) && (y + dy) < M && AM1[x + dx][y + dy] == '1')
			{
				BFS_queue1.emplace(x + dx, y + dy, cnt + 1);
				AM1[x + dx][y + dy] = '0';
			}
		}
	}
	return mcnt;
}

int main()
{
	_FASTIOS;
	cin >> N >> M;
	vector<bsc> AM1(N);
	for (auto& bsc1 : AM1) cin >> bsc1;
	cout << BFS(0, 0, AM1);
}

// solve
