#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, r, c, r1, c1, d1{};
	cin >> n;
	vector<vector<int>> ch(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> ch[i][j];
			if(ch[i][j] == 5)
			{
				r = i;
				c = j;
			}
			else if(ch[i][j] == 2)
			{
				r1 = i;
				c1 = j;
			}
		}
	}
	if (r > r1) swap(r, r1);
	if (c > c1) swap(c, c1);
	for(int i = r; i <= r1; i++)
	{
		for(int j = c; j <= c1; j++)
		{
			if (ch[i][j] == 1) d1++;
		}
	}
	auto pw = [](int i) { return i * i; };
	if (d1 >= 3 && sqrt(pw(r1 - r) + pw(c1 - c)) >= 5) cout << 1;
	else cout << 0;
}

// solve