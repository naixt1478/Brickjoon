#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0);
using namespace std;
namespace rng = ranges;
typedef long long int lli;

int main()
{
	_FASTIOS
	int N,max1{0}, i{};
	cin >> N;
	vector<int> v1(N);
	for(auto& num : v1) cin >> num;
	rng::sort(v1, greater<>());
	for(auto& num : v1) if (max1 < num * ++i) max1 = num * i;
	cout << max1;
}

// solve