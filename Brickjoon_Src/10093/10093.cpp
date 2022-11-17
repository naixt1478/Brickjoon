#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int a, b;
	cin >> a >> b;
	a++;
	cout << (b-a < 0 ? 0 : b-a) << '\n';
	for (; a < b;a++)
	{
		cout << a << ' ';
	}
}

// solve