#include <bits/stdc++.h>
using namespace std;

int main()
{
	int sum1,a;
	pair<int, int> pii1 = {0,0};
	for (int i = 1; i <= 5; i++)
	{
		sum1 = 0;
		for (int j = 0; j < 4; j++)
		{
			cin >> a;
			sum1 += a;
		}
		if (pii1.second < sum1)
		{
			pii1.first = i;
			pii1.second = sum1;
		}
	}
	cout << pii1.first << ' ' << pii1.second;
}

// solve