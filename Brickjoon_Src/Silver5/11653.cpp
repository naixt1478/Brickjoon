#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int n,i=2;
	cin >> n;
	while (n != 1)
	{
		if (n % i == 0)
		{
			n /= i;
			cout << i << '\n';
		}
		else i++;
	}
}

// solve