#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, a{1}, b{0}, temp{0};
	cin >> n;
	while(n--)
	{
		temp = a;
		a = b;
		b += temp;
	}
	cout << a << ' ' << b;
}

// solve