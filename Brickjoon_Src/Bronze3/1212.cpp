#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
typedef basic_string<char> bsc;

int main()
{
	_FASTIOS;
	int num,a{},b{},c{};
	bsc bsc1;
	cin >> bsc1;
	deque<int> bin1;
	for(auto c1 : bsc1)
	{
		c1 -= '0';
		a = c1 % 2;
		c1 /= 2;
		b = c1 % 2;
		c1 /= 2;
		c = c1 % 2;
		bin1.emplace_back(c);
		bin1.emplace_back(b);
		bin1.emplace_back(a);
	}
	for(auto i1: bin1)
	{
		if (i1 == 1) break;
		else bin1.pop_front();
	}
	if (bin1.empty()) bin1.emplace_front(0);
	for(auto& c1 : bin1) cout << dec << c1;
}

// solve