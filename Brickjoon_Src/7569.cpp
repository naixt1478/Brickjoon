#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
using namespace std;
namespace rng = ranges;
using lli = long long int;
using bsc = basic_string<char>;
using vi = vector<int>;
int X, Y, Z;

struct info
{
	int x, y, z;
};

vector<info> comp = {info(0,0,1),info(0,0,-1),info(1,0,0),info(0,1,0),info(-1,0,0),info(0,-1,0)};

int BFS_edit1(vector<vector<vi>> XYZ1)
{
	int mcnt{};
	queue<info> BFS_queue1;
	for (int z = 0; z < Z; z++)
		for (int y = 0; y < Y; y++)
			for (int x = 0; x < X; x++)
				if (XYZ1[z][y][x] == 1) BFS_queue1.emplace(x,y,z);
	while (BFS_queue1.empty() != 1)
	{
		auto [x, y, z] = BFS_queue1.front();
		BFS_queue1.pop();
		mcnt = (mcnt < XYZ1[z][y][x] ? XYZ1[z][y][x] : mcnt);
		for (auto& [dx, dy, dz] : comp)
		{
			if (0 <= (x + dx) && (x + dx) < X && 0 <= (y + dy) && (y + dy) < Y && 0 <= (z + dz) && (z + dz) < Z && XYZ1[z + dz][y + dy][x + dx] == 0)
			{
				BFS_queue1.emplace(x + dx, y + dy,z + dz);
				XYZ1[z + dz][y + dy][x + dx] = XYZ1[z][y][x] + 1;
			}
		}
	}
	for (auto& XY1 : XYZ1)
		for (auto& X1 : XY1)
			for(auto& now : X1)
				if (now == 0) return -1;
	return mcnt - 1;
}

int main()
{
	_FASTIOS;
	int t, min1{};
	cin >> X >> Y >> Z;
	vector<vector<vi>> XYZ1(Z, vector<vi>(Y));
	for (auto& XY1 : XYZ1)
	{
		for (auto& X1 : XY1)
		{
			for (int i = 0; i < X; i++)
			{
				cin >> t;
				X1.emplace_back(t);
			}
		}
	}
	cout << BFS_edit1(XYZ1) << '\n';
}

// solve
