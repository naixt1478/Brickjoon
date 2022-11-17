#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	_FASTIOS;
	int n, sum{};
	vector<int> vi1;
	while (cin >> n, n != -1)
	{
		vi1.clear();
		sum = 0;
		for (int i = 1; i <= n / 2; i++)
		{
			if (n % i == 0)
			{
				vi1.emplace_back(i);
				sum += i;
			}
		}
		if (sum != n) cout << n << " is NOT perfect.\n";
		else
		{
			cout << n << " = ";
			for (int i = 0; i < vi1.size() - 1; i++) cout << vi1[i] << " + ";
			cout << vi1[vi1.size() - 1] << '\n';
		}
	}
}

// solve