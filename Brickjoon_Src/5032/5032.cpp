#include <bits/stdc++.h>
using namespace std;

int main()
{
	int e, f, c, sum1{}, sum2{}, t1{};
	cin >> e >> f >> c;
	sum1 += e + f;
	while (sum1 >= c)
	{
		t1 = sum1 / c;
		sum2 += t1;
		sum1 %= c;
		sum1 += t1;
	}
	cout << sum2;
}

// solve