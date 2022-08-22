#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
constexpr int s1_max = 100001;

int env_s1(int n)
{
	vector<pair<int, int>> vpii1(n);
	for (auto& [i1, i2] : vpii1) cin >> i1 >> i2;
	rng::sort(vpii1);
	int upos = s1_max, i1{0};
	for(auto& [_i,__i] : vpii1)
	{
		if(__i < upos)
		{
			i1++;
			upos = __i;
		}
	}
	return i1;
}

int main()
{
	__fastios;
	int T,i1;
	cin >> T;
	while(T--)
	{
		cin >> i1;
		cout << env_s1(i1) << '\n';
	}
}

// solve