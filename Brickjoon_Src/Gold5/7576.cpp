#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
using namespace std;
namespace rng = ranges;
using lli = long long int;
using bsc = basic_string<char>;
using vi = vector<int>;
int X, Y;

struct info
{
	int x, y;
};

vector<info> comp = { info(1,0),info(0,1),info(-1,0),info(0,-1)};

int BFS_edit1(vector<vi> XY1)
{
	int mcnt{};
	queue<info> BFS_queue1;
	for (int y = 0; y < Y; y++)
		for (int x = 0; x < X; x++)
			if (XY1[y][x] == 1) BFS_queue1.emplace(x, y);
	while (BFS_queue1.empty() != 1)
	{
		auto [x, y] = BFS_queue1.front();
		BFS_queue1.pop();
		mcnt = (mcnt < XY1[y][x] ? XY1[y][x] : mcnt);
		for (auto& [dx, dy] : comp)
		{
			if (0 <= (x + dx) && (x + dx) < X && 0 <= (y + dy) && (y + dy) < Y && XY1[y + dy][x + dx] == 0)
			{
				BFS_queue1.emplace(x + dx, y + dy);
				XY1[y + dy][x + dx] = XY1[y][x] + 1;
			}
		}
	}
	for (auto& X1 : XY1)
		for (auto& now : X1)
			if (now == 0) return -1;
	return mcnt - 1;
}

int main()
{
	_FASTIOS;
	int t;
	cin >> X >> Y;
	vector<vi> XY1(Y);
	for (auto& X1 : XY1)
	{
		for (int i = 0; i < X; i++)
		{
			cin >> t;
			X1.emplace_back(t);
		}
	}
	cout << BFS_edit1(XY1) << '\n';
}

// solve
