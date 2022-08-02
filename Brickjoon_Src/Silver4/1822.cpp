#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
	__fastios;
	int a, b, t;
	cin >> a >> b;
	map<int,int> mii1;
	vector<int> vi1,vi2;
	for (int i = 0; i < a; i++)
	{
		cin >> t;
		vi2.emplace_back(t);
	}
	for (int i = 0; i < b; i++)
	{
		cin >> t;
		mii1.insert({ t,0 });
	}
	for (auto& i1 : vi2) if (!mii1.contains(i1)) vi1.emplace_back(i1);
	rng::sort(vi1);
	if (vi1.empty()) cout << 0;
	else
	{
		cout << vi1.size() << '\n';
		for (auto& i1 : vi1) cout << i1 << ' ';
	}
}

// solve
