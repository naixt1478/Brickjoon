#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
	_FASTIOS;
	int n;
	cin >> n;
	vector<int> vi1(n);
	for (auto& i1 : vi1) cin >> i1;
	rng::sort(vi1, greater<>());
	for (auto& i1 : vi1) cout << i1 << '\n';
}

// solve