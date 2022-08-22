#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
	_FASTIOS;
	int N,T;
	cin >> N;
	vector<pair<int, int>> vpii1;
	for (int i = 0; i < N; i++)
	{
		cin >> T;
		vpii1.emplace_back(T, i);
	}
	rng::sort(vpii1, rng::greater());
	for (auto& [f1, s1] : vpii1)
	{
		cout << s1 << ' ';
	}
}