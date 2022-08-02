#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n;
	cin >> m >> n;
	vector<vector<short>> num1(m+1, vector<short>(m+1, 0)), sum1(m+1, vector<short>(m+1, 0));
	for (int i = 1; i <= m * m; i++)
	{
		cin >> num1[(i - 1) / m + 1][i];
		//sum1 = 
	}
}

// progress in solve