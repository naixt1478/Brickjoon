#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, i = 0, total = 0;
	cin >> n;
	while(total < n)
	{
		i++;
		total += i;	
	}
	if (i % 2 == 1)
	{
		cout << 1 + (total - n) << '/' << i - (total - n);
	}
	else
	{
		cout << i - (total - n) << '/' << 1 + (total - n);
	}
}

// solve