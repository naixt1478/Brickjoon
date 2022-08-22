#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	_FASTIOS;
	basic_string<char> bsc1;
	cin >> bsc1;
	int result{1}, L = bsc1.size(), num{ (L + 1) / 2 };
	for(int i = 0; i < num; i++)
	{
		if (bsc1[i] != bsc1[L - 1 - i])
		{
			result = 0;
			break;
		}
	}
	cout << result;
}

// solve