#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0);
using namespace std;
namespace rng = ranges;
using lli = long long int;
using bsc = basic_string<char>;
int N;

vector<pair<int, int>> comp = { pair(1, 0), pair(0, 1), pair(-1, 0), pair(0, -1) };

struct info
{
	int x, y;
};

int BFS(int snode, int snode2, vector<bsc>& AM1)
{
	int count{1};
	queue<info> BFS_queue1;
	BFS_queue1.emplace(snode, snode2);
	AM1[snode][snode2] = '0';
	while (BFS_queue1.empty() != 1)
	{
		auto [x, y] = BFS_queue1.front();
		BFS_queue1.pop();
		for (auto& [dx, dy] : comp)
		{
			if (0 <= (x + dx) && (x + dx) < N && 0 <= (y + dy) && (y + dy) < N && AM1[x + dx][y + dy] == '1')
			{
				BFS_queue1.emplace(x + dx, y + dy);
				count++;
				AM1[x + dx][y + dy] = '0';
			}
		}
	}
	return count;
}

int main()
{
	_FASTIOS;
	cin >> N;
	vector<bsc> AM1(N);
	vector<int> check;
	for (auto& bsc1 : AM1) cin >> bsc1;
	for(int i = 0 ; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(AM1[i][j] == '1') check.emplace_back(BFS(i, j, AM1));
		}
	}
	rng::sort(check);
	cout << check.size() << '\n';
	for(auto& out : check) cout << out << '\n';
}

// solve