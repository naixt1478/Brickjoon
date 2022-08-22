#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template<typename T>
using v = vector<T>;
template<typename T>
using bs = basic_string<T>;

void solve(v<int>& vi1, v<int>& vi2,int count,int start, int length,int max2)
{
	if (count == max2)
	{
		for (auto& i1 : vi2)
		{
			cout << i1 << ' ';
		}
		cout << '\n';
	}
	else
	{
		for (int i = start; i < length; i++)
		{
			if (vi2.empty() || vi2[count - 1] <= vi1[i])
			{
				vi2.emplace_back(vi1[i]);
				solve(vi1, vi2, count + 1, 0, length, max2);
				vi2.pop_back();
			}
		}
	}
}

int main()
{
	__fastios;
	int N, M;
	cin >> N >> M;
	v<int> vi1(N), vi2;
	for (auto& i1 : vi1) cin >> i1;
	rng::sort(vi1);
	solve(vi1, vi2, 0, 0, vi1.size(), M);	
}

// solve