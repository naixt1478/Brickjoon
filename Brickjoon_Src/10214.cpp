#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	_FASTIOS;
	int T,a,b,a2,b2;
	cin >> T;
	while (T--)
	{
		a=0, b=0;
		for (int i = 0; i < 9; i++)
		{
			cin >> a2 >> b2;
			a += a2;
			b += b2;
		}
		if (a > b) cout << "Yonsei\n";
		else if (a < b) cout << "Korea\n";
		else cout << "Draw\n";
	}
}

// solve