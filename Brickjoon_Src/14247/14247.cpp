#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	lli N, sum{},i{};
	cin >> N;
	vector<pair<lli, lli>> HA(N);
	for(auto& [f,s] : HA) cin >> s;
	for(auto& [f,s] : HA) cin >> f;
	ranges::sort(HA);
	for(auto& [f, s] : HA) sum += f * i++ + s;
	cout << sum;
}

// solve