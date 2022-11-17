#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,a;
	string s;
	vector<vector<string>> list(201);
	cin >> n;
	while (n--)
	{
		cin >> a >> s;
		list[a].push_back(s);
	}
	for (int i = 0; i < list.size(); i++)
	{
		for (int j = 0; j < list[i].size(); j++)
		{
			cout << i << ' ' << list[i][j] << '\n';
		}
	}
}

// solve