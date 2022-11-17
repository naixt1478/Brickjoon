#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template <typename T>
using bs = basic_string<T>;

bool comp(const bs<char>& bscl, const bs<char>& bscr)
{
	int a = rng::min(bscl.length(), bscr.length());
	for (int i = 0; i < a; i++)
	{
		if (bscl[i] > bscr[i])
			return true;
		else if (bscl[i] < bscr[i]) return false;
		else continue;
	}
	return (bscl + bscr) > (bscr + bscl);
}

int main()
{
	_FASTIOS;
	int N, K, t{};
	size_t L{};
	cin >> N >> K;
	vector<bs<char>> vbsc1(N);
	for (bs<char>& bsc1 : vbsc1)
	{
		cin >> bsc1;
		if (bsc1.length() > L) L = bsc1.length();
	}
	rng::sort(vbsc1, comp);
	for (bs<char>& bsc1 : vbsc1)
	{
		if (t == 0 && bsc1.length() == L)
		{
			t = -1;
			for (size_t i = 0; i <= K - N; i++) cout << bsc1;
		}
		else cout << bsc1;
	}
}

// solve