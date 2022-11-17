#include "bits/stdc++.h"
using namespace std;
using lli = long long int;
namespace rng = ranges;

int main()
{
	int n,sum1{};
	cin >> n;
	vector<pair<int, int>> vpii1(n);
	for(auto& [i1,i2] : vpii1) cin >> i1 >> i2;
	rng::sort(vpii1);
	for(auto [i1,i2] : vpii1)
	{
		if (i1 > sum1) sum1 = i1 + i2;
		else if (sum1 >= i1) sum1 += i2;
	}
	cout << sum1;
}