#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

void s1()
{
	int x1, y1, x2, y2, T2, cx, cy, r, i1{};
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> T2;
	while (T2--)
	{
		cin >> cx >> cy >> r;
		if (cx - r < x1 && x1 < cx + r && cy - r < y1 && y1 < cy + r || cx - r < x2 && x2 < cx + r && cy - r < y2 && y2 < cy + r)
		{
			if (!(cx - r < x1 && x1 < cx + r && cy - r < y1 && y1 < cy + r && cx - r < x2 && x2 < cx + r && cy - r < y2 && y2 < cy + r))
			{
				i1++;
			}
		}
	}
	cout << i1 << '\n';
}

int main()
{
	__fastios;
	int T;
	cin >> T;
	while (T--)
	{
		s1();
	}
}