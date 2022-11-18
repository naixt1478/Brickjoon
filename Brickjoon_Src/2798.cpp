#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m, c = 0;
	cin >> n >> m;
	vector<int> b(n + 1);
	for (auto i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	for (auto i = 0; i < n; i++)
	{
		for (auto j = i + 1; j < n; j++)
		{
			for (auto u = j + 1; u < n; u++)
			{
				auto a = b[i] + b[j] + b[u];
				if (a > c && a <= m)
				{
					c = a;
				}
			}
		}
	}
	cout << c;
}

// solve