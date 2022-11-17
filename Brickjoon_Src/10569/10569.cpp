#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int T,V,E;
	cin >> T;
	while(T--)
	{
		cin >> V >> E;
		cout << abs(V - E) + 2 << '\n';
	}
}

// solve