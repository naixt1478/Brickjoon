#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template <typename T>
using bs = basic_string<T>;

int main()
{
	_FASTIOS;
	int T,f{};
	bs<char> bsc1,bsc2;
	cin >> T;
	cin.ignore();
	while(T--)
	{
		f = 0;
		getline(cin, bsc1);
		stringstream ss1(bsc1);
		while(getline(ss1,bsc2, ' '))
		{
			if (f == 0) f = 1;
			else cout << ' ';
			rng::reverse(bsc2);
			cout << bsc2;
		}
		cout << '\n';
	}
}

// solve