#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
using namespace std;
namespace rng = ranges;
using lli = long long int;
using bsc = basic_string<char>;

int main()
{
	_FASTIOS;
	int N,T,Max{},Min{};
	vector<int> num;
	cin >> N;
	while(N--)
	{
		cin >> T;
		if (Min == 0) Min = T;
		num.emplace_back(T);
		if (T > Max) Max = T;
		if (T < Min) Min = T;
	}
	rng::sort(num);
	cout << Max * Min;
}

// solve