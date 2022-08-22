#include <iostream>

using namespace std;

int main()
{
	int a, b, n, n2;
	cin >> n >> n2;
	a = n, b = n2;
	while (b != 0)
	{
		int t = a % b;
		a = b, b = t;
	}
	cout << a << "\n";
	cout << (n * n2 / a);
}

// solve