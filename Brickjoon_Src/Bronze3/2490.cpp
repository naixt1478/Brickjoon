#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int i(3),n,t,r;
	while (i--)
	{
		r = 0;
		for (int j(0); j < 4; j++)
		{
			cin >> t;
			r += t;
		}
		if (r == 4) cout << "E\n";
		else if (r == 3) cout << "A\n";
		else if (r == 2) cout << "B\n";
		else if (r == 1) cout << "C\n";
		else cout << "D\n";
	}
}

// solve
