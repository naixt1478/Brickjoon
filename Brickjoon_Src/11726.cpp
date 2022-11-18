#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
using namespace std;
namespace rng = ranges;
using lli = long long int;
using bsc = basic_string<char>;
constexpr int mod = 10007;

int main()
{
	_FASTIOS;
	int N;
	cin >> N;
	vector<int> num = {1,1};
	for(int i = 2; i <= N; i++) num.emplace_back((num[i - 1] + num[i - 2])%mod);
	cout << num[N];
}

// solve