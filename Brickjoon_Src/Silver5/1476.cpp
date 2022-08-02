#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
using namespace std;
namespace rng = ranges;
typedef long long int lli;

int main()
{
	_FASTIOS;
	int E, S, M, cnt{1};
	cin >> E >> S >> M;
	while((cnt - E ) % 15 != 0 || (cnt - S) % 28 != 0 || (cnt - M) % 19 != 0) cnt++;
	cout << cnt;
}

// solve...?