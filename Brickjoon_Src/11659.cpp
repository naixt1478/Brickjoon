#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int m, n, i, j;
	cin >> m >> n;
	vector<int> num(m+1), sum(m+1);
	for (int k = 1; k <= m; k++)
	{
		cin >> num[k];
		sum[k] = sum[k - 1] + num[k];
	}

	while (n--)
	{
		cin >> i >> j;
		cout << sum[j] - sum[i-1] << '\n';
	}
}

// solve