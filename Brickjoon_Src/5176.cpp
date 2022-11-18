#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int solve(int a, int b,int c = 0,int d = 0)
{
	vector<int> vi1(b + 1);
	while (a--)
	{
		cin >> c;
		if (!vi1[c]) vi1[c] = 1;
		else d += 1;
	}
	return d;
}

int main()
{
	__fastios;
	int T,a,b;
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		cout << solve(a, b) << '\n';
	}
}

// solve