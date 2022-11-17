#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

void s1()
{
	int x1, y1, x2, y2, T2, cx, cy, r, i1{};
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> T2;
	while(T2--)
	{
		cin >> cx >> cy >> r;
		long double r1 = powl(x1 - cx, 2) + powl(y1 - cy, 2);
		long double r2 = powl(x2 - cx, 2) + powl(y2 - cy, 2);
		if(r1 >= r*r xor r2 >= r*r)
		{
			i1++;
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

// solve