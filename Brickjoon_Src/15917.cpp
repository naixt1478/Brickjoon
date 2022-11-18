#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int q,a;
	cin >> q;
	while(q--)
	{
		cin >> a;
		cout << ((a & (-a)) == a) << '\n';
	}
}

// solve