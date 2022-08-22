#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
int sel1 = 0;

bool comp(const pair<int, vector<int>> &a, const pair<int, vector<int>> &b)
{
	if (a.second[sel1] == b.second[sel1])
		return a.first > b.first;
	else
		return a.second[sel1] < b.second[sel1];
}

vector<int> vi1_i()
{
	vector<int> vi1(4);
	for (auto& i1 : vi1) cin >> i1;
	return vi1;
}

int main()
{
	__fastios;
	int T,a;
	cin >> T;
	vector<pair<int, vector<int>>> vpivi1;
	for(int i = 0; i < T; i++)
	{
		cin >> a;
		vpivi1.emplace_back(pair(a, vi1_i()));
	}
	for(int i = 0; i < 4; i++)
	{
		sel1 = i;
		if (vpivi1.empty()) break;
		rng::sort(vpivi1, comp);
		cout << vpivi1.back().first << ' ';
		vpivi1.pop_back();
	}
}

// solve