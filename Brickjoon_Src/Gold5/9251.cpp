#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template <typename T>
using bs = basic_string<T>;

int main()
{
	__fastios;
	int max1{};
	bs<char> bsc1, bsc2;
	cin >> bsc1 >> bsc2;
	vector<vector<int>> vvi1(bsc1.length()+1, vector<int>(bsc2.length()+1));
	for (size_t i = 1; i <= bsc1.length(); i++)
	{
		for (size_t j = 1; j <= bsc2.length(); j++)
		{
			if (bsc1[i - 1] == bsc2[j - 1])
			{
				vvi1[i][j] = vvi1[i - 1][j - 1] + 1;
				if (vvi1[i][j] > max1) max1 = vvi1[i][j];
			}
			else vvi1[i][j] = rng::max(vvi1[i-1][j], vvi1[i][j-1]);
		}
	}
	cout << max1;
}

// solve