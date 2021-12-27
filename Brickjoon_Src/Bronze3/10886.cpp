#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n,a(0),b(0),i(0);
	cin >> n;
	while (n--)
	{
		cin >> i;
		if (i) a++;
		else b++;
	}
	cout << (a > b ? "Junhee is cute!" : "Junhee is not cute!");
}

// solve