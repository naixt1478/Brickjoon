#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;
namespace rng = ranges;

int main()
{
	_FASTIOS
	int N, t;
	cin >> N;
	vector<int> num(N), num2(N);
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		num[i] = t;
		num2[i] = t;
	}
	rng::sort(num);
	auto a1 = rng::unique(num);
	num.erase(a1.begin(), a1.end());
	for (int i = 0; i < N; i++)
	{
		cout << rng::lower_bound(num, num2[i]) - num.begin() << ' ';
	}
}

// solve