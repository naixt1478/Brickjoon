#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
using lli = long long int;

int main()
{
	_FASTIOS;
	int n,t;
	lli max1{0};
	cin >> n;
	vector<int> vi1(n);
	for (auto& i1 : vi1)
	{
		cin >> i1;
		if (i1 > max1) max1 = i1;
	}
	for (int i = 1; i < n - 1; i++)
	{
		t = vi1[i] + rng::min(vi1[i - 1], vi1[i + 1]);
		if (t > max1) max1 = t;
	}
	cout << max1;
}

// solve