#include "bits/stdc++.h"
using namespace std;

int main()
{
	int a, b, c{1}, d{}, sum1{};
	cin >> a >> b;
	for(int i = 0; i < b; i++)
	{
		d++;
		if(c < d)
		{
			c++;
			d = 1;
		}
		if(i+1 >= a)
		{
			sum1 += c;
		}
	}
	cout << sum1;
}

// solve