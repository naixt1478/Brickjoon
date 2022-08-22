#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template <typename T>
using V = vector<T>;

int main()
{
	__fastios;
	basic_string<char> bsc1;
	int i{0};
	cin >> bsc1;
	for (auto& c1 : bsc1)
	{
		if (c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u') i++;
	}
	cout << i;
}

// solve