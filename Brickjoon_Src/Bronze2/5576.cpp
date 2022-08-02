#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
	_FASTIOS;
	vector<vector<int>> AB(2, vector<int>(10));
	for (auto& vi1 : AB)
	for (auto& i1 : vi1)
	cin >> i1;
	rng::sort(AB[0],rng::greater());
	rng::sort(AB[1],rng::greater());
	cout << AB[0][0] + AB[0][1] + AB[0][2] << ' ' << AB[1][0] + AB[1][1] + AB[1][2];
}

// solve