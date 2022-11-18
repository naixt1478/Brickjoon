#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
using namespace std;
namespace rng = ranges;
typedef long long int lli;

int main()
{
	_FASTIOS;
	lli n, i{}, sum2{};
	cin >> n;
	vector<lli> v1(n-1), v2(n);
	for (auto& n : v1) cin >> n;
	for (auto& n : v2) cin >> n;
	while(i != n-1)
	{
		lli sum = 0; 
		for(lli j = i; j < n; j++)
		{
			if(j == (n - 1) || v2[i] > v2[j])
			{
				sum2 += sum * v2[i];
				i = j;
				break;
			}
			else sum += v1[j];
		}
	}
	cout << sum2;
}

// solve