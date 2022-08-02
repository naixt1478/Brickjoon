#include <iostream>
#include <string>

using namespace std;

int main()
{
	string m, d;
	cin >> m;
	int a, b, n, c = stoi(m);
	for (int i = c; i > 0; i--)
	{
		a = 0;
		d = to_string(i);
		b = d.length() - 1;

		for (int j = b; j >= 0; j--)
			a += (d.at(j) - '0');

		if ((i + a) == c)
			n = i;
	}
	cout << n;
}

// solve