#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n,a,b,c;
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> c;
		cout << (a < (b-c) ? "advertise" : (a == (b-c) ? "does not matter" : "do not advertise")) << '\n';
	}
}

// solve