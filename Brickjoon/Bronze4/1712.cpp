#include <iostream>

using namespace std;

long long solve1()
{
	long a, b, c;
	cin >> a >> b >> c;
	if (b >= c)
		return -1;
	c -= b;
	a = (a / c)+1;
	return a;
}

int main()
{
	long long result = solve1();
	cout << result;
	return 0;
}

// solved