#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template <typename T>
using bs = basic_string<T>;

int main()
{
	_FASTIOS;
	int N, M, sum1{};
	cin >> N >> M;
	bs<char> bsc2;
	vector<bs<char>> vbsc1(N);
	for (auto& bsc1 : vbsc1) cin >> bsc1;
	rng::sort(vbsc1);
	while (M--)
	{
		cin >> bsc2;
		sum1 += rng::binary_search(vbsc1, bsc2);
	}
	cout << sum1;
}

// solve