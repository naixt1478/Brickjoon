#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
typedef basic_string<char> bsc;

int main()
{
	_FASTIOS;
	bsc bsc1;
	vector<bsc> vbsc1;
	vector<size_t> vbscl1;
	for(int i = 0; i < 5; i++)
	{
		cin >> bsc1;
		vbsc1.emplace_back(bsc1);
		vbscl1.emplace_back(bsc1.length());
	}
	const size_t maxl1 = *rng::max_element(vbscl1);
	for(size_t i = 0; i < maxl1; i++)
	{
		for(size_t j = 0; j < 5; j++) if(vbscl1[j] > i) cout << vbsc1[j][i];
	}
}

// solve