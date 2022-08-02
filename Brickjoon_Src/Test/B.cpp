#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	_FASTIOS;
	int T, sum{},a2,b2,c2,d2;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int a = 1000000, b = 1000000, c = 1000000, d = 1000000;
		for (int i = 0; i < 3; i++)
		{
			cin >> a2 >> b2 >> c2 >> d2;
			a = min(a, a2);
			b = min(b, b2);
			c = min(c, c2);
			d = min(d, d2);
		}
		cout << "Case #" << i << ": ";
		if (a + b + c + d < 1000000) cout << "IMPOSSIBLE";
		else
		{
			int sum = (a + b + c + d) - 1000000;
			for (auto& i1 : { a,b,c,d })
			{
				if (i1 - sum < 0) 
				{ 
					cout << "0 ";
					sum = abs(i1 - sum);
				}
				else
				{
					cout << i1 - sum << ' ';
					sum = 0;
				}
			}
		}
		cout << '\n';
	}
}

// solve