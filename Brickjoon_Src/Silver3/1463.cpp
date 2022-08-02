#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;
namespace rng = ranges;

int main()
{
	_FASTIOS
	int N,i{-1};
	cin >> N;
	vector<int> num(N+1);
	for(auto& r : num)
	{
		if (++i < 2) continue;
		r = num[i - 1] + 1;
		if (i % 2 == 0) r = rng::min(num[i/2] + 1, r);
		if (i % 3 == 0) r = rng::min(num[i/3] + 1, r);
	}
	cout << num[N];
}

// solve