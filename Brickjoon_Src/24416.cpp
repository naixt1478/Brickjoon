#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,buf,b=0,f=1;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		buf = b + f;
		b = f;
		f = buf;
	}
	cout << f << ' ' << n - 2;
}

// solve