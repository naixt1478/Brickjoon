#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template<typename T>
using v = vector<T>;
template<typename T>
using bs = basic_string<T>;
bitset<11> bit1;

void solve(bs<char>& bsc1, bs<char>& bsc2,int count,int& count2,int start, int length,int max2)
{
	if (count == max2)
	{
		count2--;
		if (count2 == 0)
		{
			for (auto& c1 : bsc2)
			{
				cout << c1;
			}
			cout << '\n';
		}
	}
	else
	{
		for (int i = start; i < length; i++)
		{
			if (!bit1[i])
			{
				bit1[i] = 1;
				bsc2.push_back(bsc1[i]);
				solve(bsc1, bsc2, count + 1, count2, 0, length, max2);
				bsc2.pop_back();
				bit1[i] = 0;
			}
		}
	}
}

int main()
{
	__fastios;
	int N;
	bs<char> bsc1,bsc2;
	while(true)
	{
		cin >> bsc1 >> N;
		if (cin.eof()) break;
		bs<char>().swap(bsc2);
		cout << bsc1 << " " << N << " = ";
		if (N == 0) cout << bsc1 << '\n';
		else solve(bsc1, bsc2, 0, N, 0, bsc1.size(), bsc1.size());
		if (N > 0) cout << "No permutation\n";
	}
}

// solve