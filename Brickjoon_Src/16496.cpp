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
	int N, t{}, t2{};
	size_t L{};
	cin >> N;
	vector<bs<char>> vbsc1(N);
	for (bs<char>& bsc1 : vbsc1)
	{
		cin >> bsc1;
		if (bsc1.length() > L) L = bsc1.length();
	}
	rng::sort(vbsc1, comp);
	for (size_t i = 0; i < N; i++)
	{
		if (i != N - 1 && t2 == 0 && vbsc1[i] == "0") continue;
		else if (i == N - 1 && t2 == 0 && vbsc1[i] == "0") cout << 0;
		else
		{
			t2 = -1;
			cout << vbsc1[i];
		}
	}
}
// from problem 1422
// 
// solve 