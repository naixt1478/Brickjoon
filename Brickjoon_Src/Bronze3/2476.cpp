#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
	_FASTIOS;
	vector<int> vi1(3);
	int N, max1{}, sum1{};
	cin >> N;
	while (N--)
	{
		sum1 = 0;
		cin >> vi1[0] >> vi1[1] >> vi1[2];
		rng::sort(vi1);
		if (vi1[0] == vi1[2]) sum1 = 10000 + vi1[0] * 1000;
		else if (vi1[0] == vi1[1] || vi1[0] == vi1[2]) sum1 = 1000 + vi1[0] * 100;
		else if (vi1[1] == vi1[2]) sum1 = 1000 + vi1[1] * 100;
		else sum1 = vi1[2] * 100;
		if (sum1 > max1) max1 = sum1;
	}
	cout << max1;
}

// solve