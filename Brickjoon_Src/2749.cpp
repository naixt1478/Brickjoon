#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int const n = 15000000;

int main()
{
	int const m = 1000000;
	lli n;
	lli const pisa = m/10 * 15;
	cin >> n;
	vector<lli> num(pisa+1);
	num[1] = 1;
	
	for (int i = 2; i < pisa; i++)
	{
		num[i] = num[i - 2] + num[i - 1];
		num[i] %= m;
	}
	cout << num[n % pisa];
}

// solve