#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
template <typename T>
using bs = basic_string<T>;

int main()
{
	_FASTIOS;
	int n, r{0};
	bs<char> bsc1;
	stack<char> sc1;
	cin >> n;
	while (n--)
	{
		cin >> bsc1;
		stack<char>().swap(sc1);
		for (char& c1 : bsc1)
		{
			if (sc1.empty()) sc1.emplace(c1);
			else if (sc1.top() == c1) sc1.pop();
			else sc1.emplace(c1);
		}
		if (sc1.empty()) r++;
	}
	cout << r;
}

// solve