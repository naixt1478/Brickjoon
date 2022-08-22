#include <iostream>

using namespace std;

int main()
{
	int a, b, c, n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		int f = 100;
		int e = 1;
		for (int j = 0; j < c - 1; j++)
		{
			if ((j + 1) % a == 0)
			{
				f = 100;
				e++;
			}
			else
			{
				f += 100;
			}
		}
		cout << e + f << "\n";
	}
}

// solve