#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
template <typename T>
using bs = basic_string<T>;

int main()
{
	_FASTIOS;
	int T;
	double d1{};
	cin >> T;
	cin.ignore();
	while (T--)
	{
		bs<char> bsc1,bsc2;
		getline(cin, bsc1);
		stringstream ss1(bsc1);
		ss1 >> d1;
		while (getline(ss1, bsc2, ' '))
		{
			if (bsc2 == "@") d1 *= 3;
			else if (bsc2 == "#") d1 -= 7;
			else if (bsc2 == "%") d1 += 5;
		}
		cout << fixed << setprecision(2) << d1 << '\n';
	}
}

// solve
