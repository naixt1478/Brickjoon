#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, m, b{}, f{}, min1{}, c1, c2;
	cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	while (b <= (n - 8))
	{
		if (f > m - 8) { b++; f = 0; continue; };
		c1 = 0, c2 = 0;
		for (int i = 0 + b; i < 8 + b; i++)
		{
			for (int j = 0 + f; j < 8 + f; j++)
			{
				if ((j + 1 + (i-b)) % 2 == 0)
				{
					if (s[i][j] == 'W') c2++;
					else c1++;
				}
				else
				{
					if (s[i][j] == 'B') c2++;
					else c1++;
				}
			}
		}
		if (f == 0 && b == 0) min1 = min(c1, c2);
		else if (min1 > min(c1, c2)) min1 = min(c1, c2);
		f++;
	}
	cout << min1;
}

// solve
