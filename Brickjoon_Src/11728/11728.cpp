#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	_FASTIOS;
	int N, M, a{}, b{};
	cin >> N >> M;
	vector<int> vi1(N), vi2(M), vi3;
	for (auto& i1 : vi1) cin >> i1;
	for (auto& i1 : vi2) cin >> i1;
	while (true)
	{
		if (a == vi1.size() && b == vi2.size()) break;
		else if (a == vi1.size() || b != vi2.size() && vi1[a] >= vi2[b])
		{
			vi3.emplace_back(vi2[b]);
			b++;
		}
		else if (b == vi2.size() || a != vi1.size() && vi1[a] < vi2[b])
		{
			vi3.emplace_back(vi1[a]);
			a++;
		}
	}
	for (auto& i1 : vi3) cout << i1 << ' ';
}

// solve