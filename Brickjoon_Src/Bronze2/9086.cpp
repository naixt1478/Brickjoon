#include <bits/stdc++.h>
using namespace std;
template<typename T>
using bs = basic_string<T>;

int main()
{
	int T;
	bs<char> bsc1;
	cin >> T;
	while (T--)
	{
		cin >> bsc1;
		cout << bsc1.front() << bsc1.back() << '\n';
	}
}

// solve