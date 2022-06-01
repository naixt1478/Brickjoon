#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long s, n{1};
	cin >> s;
	while(s >= n)
	{
		s -= n;
		n++;
	}
	cout << n-1;
}

// solve