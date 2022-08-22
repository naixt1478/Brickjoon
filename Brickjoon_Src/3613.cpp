#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
template<typename T>
using bs = basic_string<T>;
namespace rng = ranges;

int main()
{
	_FASTIOS;
	int ub{}, uc{}, lc{}, flc{-1}, eub{};
	char ec1;
	bs<char> bsc1;
	cin >> bsc1;
	for(size_t i = 0; i < bsc1.length(); i++)
	{
		if (flc == -1)
		{
			if ('a' <= bsc1[i] && bsc1[i] <= 'z') flc = 1;
			else flc = 0;
		}
		else if (bsc1[i] == '_')
		{
			if (bsc1.length() - 1 == i || bsc1[i + 1] == '_') eub = 1;
			ub = 1;
		}
		else if ('a' <= bsc1[i] && bsc1[i] <= 'z') lc = 1;
		else if ('A' <= bsc1[i] && bsc1[i] <= 'Z') uc = 1;
	}
	if(!eub && ub && lc && !uc && flc)
	{
		for(size_t i = 0; i < bsc1.length(); i++)
		{
			if(bsc1[i] == '_')
			{
				bsc1.replace(i, 2, { static_cast<char>( bsc1[i + 1] - 32) });
			}
		}
		cout << bsc1;
	}
	else if(!eub && !ub && flc)
	{
		ec1 = bsc1[bsc1.length() - 1];
		for(size_t i = 0; i < bsc1.length(); i++)
		{
			if('A' <= bsc1[i] && bsc1[i] <= 'Z')
			{
				bs<char> bs2 = { '_', static_cast<char>(bsc1[i]+32)};
				bsc1.replace(i, 1, bs2);
			}
		}
		cout << bsc1;
	}
	else
	{
		cout << "Error!";
	}
}

// solve
