#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m, n, t = 0,f = 0, min = 0,j;
	cin >> m >> n;
	for (int i = m; i <= n; i++)
	{
		if (i >= 4 && i%2==0) continue;
		else
		{
			for (j = 2; j < i; j++)
			{
				if (i % j == 0) break;
			}
			if (j != i) continue;
			if (f == 0)
			{
				min = i,f = 1;
				t += i;
			}
			else t += i;
		}
	}
	if (t == 0) cout << -1;
	else cout << t << '\n' << min;
}

// solve