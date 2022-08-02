#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n%7==0)cout << n;
		else if(7-n%7 > n%7)
		{
			cout << 7*(n/7);
		}
		else
		{
			cout << n + (7 - (n % 7));
		}
		cout << '\n';
	}
}