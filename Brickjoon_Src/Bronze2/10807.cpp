#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
	__fastios;
	int n,v;
	cin >> n;
	vector<int> vi1(n);
	for (auto& i1 : vi1) cin >> i1;
	cin >> v;
	cout << rng::count(vi1, v);
}

// solve