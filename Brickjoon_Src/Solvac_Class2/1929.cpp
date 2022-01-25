#include <iostream>
#include <vector>

using namespace std;

void b(int a)
{
	cout << a << "\n";
}

int main()
{
	int m, n, a = 0;
	cin >> m >> n;
	vector<int>	num1(n + 2, -1);
	if (m == 1)
	{
		m = 2;
	}
	for (int i = 2; i <= n; i++)
		num1[i] = i;

	for (int i = 2; i <= n; i++)
	{
		if (num1[i] == -1)
		{
			continue;
		}
		else
		{
			for (int j = 2 * i; j <= n; j += i)
			{
				num1[j] = -1;
			}
		}
	}
	for (int i = m; i <= n; i++)
	{
		if (num1[i] == -1)
			continue;
		else
			b(num1[i]);
	}
}