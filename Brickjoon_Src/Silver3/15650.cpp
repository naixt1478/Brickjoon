#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template<typename T>
using v = vector<T>;
template<typename T>
using bs = basic_string<T>;
bitset<11> bit1;

void solve(bs<char>& bsc1, bs<char>& bsc2,int count,int start, int length,int max2)
{
	if (count == max2)
	{
		for (auto& c1 : bsc2)
		{
			cout << c1 << ' ';
		}
		cout << '\n';
	}
	else
	{
		for (int i = start; i < length; i++)
		{
			if (!bit1[i])
			{
				bit1[i] = 1;
				bsc2.push_back(bsc1[i]);
				solve(bsc1, bsc2, count + 1, i + 1, length, max2);
				bsc2.pop_back();
				bit1[i] = 0;
			}
		}
	}
}

int main()
{
	__fastios;
	bs<char> bsc1,bsc2;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) bsc1.push_back(i + '0');
	solve(bsc1, bsc2, 0, 0, bsc1.length(), M);	
}

// solve
