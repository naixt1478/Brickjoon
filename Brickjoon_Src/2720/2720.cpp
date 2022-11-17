#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int t, c;
	vector<int> mod = {25,10,5,1};
	cin >> t;
	while(t--)
	{
		cin >> c;
		for(int m : mod)
		{
			cout << c / m << ' ';
			c %= m;
		}
		cout << '\n';
	}
}

// solve