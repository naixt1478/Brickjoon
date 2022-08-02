#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
template <typename T>
using bs = basic_string<T>;

int main()
{
	_FASTIOS;
	bs<char> bsc1;
	cin >> bsc1;
	int sum1{}, t{};
	for (auto c1 : bsc1)
	{
		if (t != c1) sum1 += 10;
		else sum1 += 5;
		t = c1;
	}
	cout << sum1;
}

// solve