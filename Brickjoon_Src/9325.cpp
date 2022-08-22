#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	__fastios;
	int T,s,n,a,b;
	cin >> T;
	while (T--)
	{
		cin >> s >> n;
		while (n--)
		{
			cin >> a >> b;
			s += a * b;
		}
		cout << s << '\n';
	}
}

// solve