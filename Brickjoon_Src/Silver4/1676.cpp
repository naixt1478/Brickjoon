#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0);
using namespace std;
namespace rng = ranges;
typedef long long int lli;

int main()
{
	_FASTIOS;
	int N,sum{},sum2{},temp{};
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		temp = i;
		while(temp%5 == 0)
		{
			temp /= 5;
			sum2++;
		}
		while(temp%2 == 0)
		{
			temp /= 2;
			sum++;
		}
	}
	cout << rng::min(sum, sum2);
}

// solve