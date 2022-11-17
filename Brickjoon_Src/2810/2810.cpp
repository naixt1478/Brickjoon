#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
using namespace std;
namespace rng = ranges;
using lli = long long int;
using bsc = basic_string<char>;

int main()
{
	_FASTIOS;
	int N, sum{1};
	cin >> N;
	bsc bsc1;
	cin >> bsc1;
	for(int i = 0; i < N; i++)
	{
		sum++;
		if(bsc1[i] == 'L') i++;
	}
	if (sum >= N) cout << N;
	else cout << sum;
}

// solve