#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int a, b, c{ -1 }, d{0};
	cin >> a >> b;
	cout << a / b << '.';
	while(c!=0)
	{
		a = (a % b) * 10;
		cout << a / b;
		c = a % b;
		d++;
		if (d > 1001) break;
	}
}

// solve