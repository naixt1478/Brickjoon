#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t, s1{}, a,b, s2;
	cin >> t;
	while (t--)
	{
		int n, H, M;
		cin >> n >> H >> M;
		s1 = H * 60 + M;
		s2 = -1;
		while (n--)
		{
			cin >> a >> b;
			if (s2 == -1 || (s1 <= a * 60 + b && a * 60 + b < s2))
			{
				s2 = a * 60 + b;
			}
		}
		cout << s2 / 60 << ' ' << s2 % 60 << '\n';
	}
}