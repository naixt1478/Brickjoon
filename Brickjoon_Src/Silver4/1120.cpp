#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template <typename T>
using bs = basic_string<T>;

int main()
{
	_FASTIOS;
	int max1{ 51 }, sum{};
	bs<char> bsc1, bsc2;
	cin >> bsc1 >> bsc2;
	for (int i = 0; i <= bsc2.length() - bsc1.length(); i++)
	{
		sum = 0;
		for (int j = 0; j < bsc1.length(); j++)
		{
			if (bsc2[i + j] != bsc1[j]) sum++;
		}
		if (sum < max1) max1 = sum;
	}
	cout << max1;
}

// solve
