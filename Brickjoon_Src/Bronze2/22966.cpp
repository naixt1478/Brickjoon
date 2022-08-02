#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, min1{5},t;
	basic_string<char> bsc1,bsc2;
	cin >> n;
	while (n--)
	{
		cin >> bsc1 >> t;
		if (t < min1)
		{
			bsc2 = bsc1;
			min1 = t;
		}
	}
	cout << bsc2;
}

// solve