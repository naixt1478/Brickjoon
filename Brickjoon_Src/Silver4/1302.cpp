#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
using pibsc = pair<int, basic_string<char>>;

bool comp(const pibsc& a, const pibsc& b)
{
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main()
{
	__fastios;
	int n;
	cin >> n;
	basic_string<char> bsc2;
	vector<pibsc> vpibsc1;
	while(n--)
	{
		cin >> bsc2;
		size_t vl1 = vpibsc1.size();
		for (int i = 0; i <= vl1; i++)
		{
			if (i == vl1) vpibsc1.emplace_back(1, bsc2);
			else if (vpibsc1[i].second == bsc2) vpibsc1[i].first++;
			else continue;
			break;
		}
	}
	rng::sort(vpibsc1, comp);
	cout << vpibsc1[0].second;
}

// solve
