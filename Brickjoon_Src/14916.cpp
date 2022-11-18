#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int a, t{0};
	cin >> a;
	t = a / 5 + 1;
	while(--t > -1)
	{
		if((a-t*5)%2 == 0)
		{
			t += (a - t * 5) / 2;
			break;
		}
	}
	cout << t;
}

// solve