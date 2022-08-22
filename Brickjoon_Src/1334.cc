#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cout.tie(nullptr),cin.tie(nullptr)
using namespace std;
namespace rng = ranges;
template<typename T>
using bs = basic_string<T>;


bool up(basic_string<char> &s1, long long int pos)
{
	s1[pos]++;
	for(pos = pos;pos>=0;pos--)
	{
		if(s1[pos] >= ':')
		{
			if(pos-1 < 0)
			{
				s1[pos] = '0';
				s1.insert(0, "1");
			}
			else
			{
				s1[pos] = '0';
				s1[pos - 1] += 1;
			}
		}
		else break;
	}
	return 1;
}

int main()
{
	__fastios;
	bool b1 = false;
	bs<char> bsc1;
	cin >> bsc1;
	up(bsc1, bsc1.length() - 1);
	for(size_t i = 0; i <= (bsc1.length() / 2); i++)
	{
		char &a = bsc1[i], &b = bsc1[bsc1.length() - 1 - i];
		if (a == b) continue;
		else if (a > b)
		{
			b = a;
			i--;
		}
		else if (a < b)
		{
			b = a;
			up(bsc1, bsc1.length() - 2 - i);
			i--;
		};

	}
	cout << bsc1;
}

// solve