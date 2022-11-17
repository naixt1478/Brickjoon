#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
struct d2
{
	int x, y;
};
// dimension var (ex x,y,z ...)

int M, N, K;
vector<d2> path = { d2(1,0),d2(0,1),d2(-1,0),d2(0,-1) };

void bfs_edit1(int x, int y, vector<vector<int>>& Vd2, vector<vector<int>>& ch)
{
	queue<d2> bfs1q1; // bfs queue
	bfs1q1.emplace(x, y); // first search x,y in
	ch[x][y] = 1; 
	while (bfs1q1.empty() != 1)
	{
		auto [x1, y1] = bfs1q1.front(); 
		bfs1q1.pop();
		for (auto& [dx, dy] : path)
		{
			if (0 <= (x1 + dx) && (x1 + dx) < M && 0 <= (y1 + dy) && (y1 + dy) < N && Vd2[x1 + dx][y1 + dy] == 1 && ch[x1 + dx][y1 + dy] == 0)
			{
				bfs1q1.emplace(x1 + dx, y1 + dy);
				ch[x1 + dx][y1 + dy] = 1;
			}
		}
	}
}

int s1()
{
	int x, y, i1 = 0;
	cin >> M >> N >> K;
	vector<vector<int>> vvi1(M, vector<int>(N)); // Get 2D array
	vector<vector<int>> vvi2(M, vector<int>(N)); // checking 2D array
	while (K--)
	{
		cin >> x >> y;
		vvi1[x][y] = 1;
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vvi2[i][j] == 0 && vvi1[i][j] == 1)
			{
				i1++; // counting
				bfs_edit1(i, j, vvi1, vvi2);
			}
		}
	}
	return i1; // output count
}

int main()
{
	__fastios;
	int T;
	cin >> T;
	while (T--) cout << s1() << '\n';
}

// solve