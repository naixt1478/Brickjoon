#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n, sum1{};
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum1 += i + j;
		}
	}
	cout << sum1;
}

// solve