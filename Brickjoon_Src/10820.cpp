#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template<typename T>
using bs = basic_string<T>;

int main()
{
	_FASTIOS;
	bs<char> bsc1;
	while(getline(cin,bsc1) && !cin.eof())
	{
		int a{}, b{}, c{}, d{};
		for(auto& c1 : bsc1)
		{
			if ('a' <= c1 && c1 <= 'z') a++;
			else if ('A' <= c1 && c1 <= 'Z') b++;
			else if ('0' <= c1 && c1 <= '9') c++;
			else if (c1 == ' ') d++;
		}
		cout << a << ' ' << b << ' ' << c << ' ' << d << "\n";
	}
}

// solve