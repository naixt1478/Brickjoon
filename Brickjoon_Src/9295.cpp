#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	__fastios;
	int T,a,b;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> a >> b;
		cout << "Case " << i << ": " << a + b << '\n';
	}
}

// solve