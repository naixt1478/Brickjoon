#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;
namespace rng = ranges;

int main()
{
	_FASTIOS
	int N,L;
	char c;
	cin >> N;
	vector<basic_string<char>> vbsc1(N);
	for (auto& bsc : vbsc1) cin >> bsc;
	L = vbsc1[0].length();
	for(int i = 0; i < L; i++)
	{
		c = vbsc1[0][i];
		for(auto& bsc : vbsc1)
		{
			if(c != bsc[i])
			{
				vbsc1[0][i] = '?';
				break;
			}
		}
	}
	cout << vbsc1[0];
}

// solve