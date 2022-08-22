#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template <typename T>
using bs = basic_string<char>;

int main()
{
	_FASTIOS;
	bs<char> bsc1;
	getline(cin, bsc1);
	for(auto& c1 : bsc1)
	{
		int num = c1 + 13;
		if ('A' <= c1 && c1 <= 'Z')
		{
			c1 = 'A' + ((num-'A') % 26);
		}
		else if ('a' <= c1 && c1 <= 'z')
		{
			c1 = 'a' + ((num-'a') % 26);
		}
	}
	cout << bsc1;
}

// solve