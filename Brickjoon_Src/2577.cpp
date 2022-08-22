#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	vector <int> d(10);
	string str = to_string(a * b * c);
	for (int i = 0; i < 10; i++)
	{
		a = 0, d[i] = 0;
		while (1)
		{
			c = str.find(48 + i, a);
			if (c < 0)
				break;
			else
				d[i] += 1, a = c + 1;
		}
	}
	for (int i = 0; i < 10; i++)
		cout << d[i] << "\n";
}

// solve