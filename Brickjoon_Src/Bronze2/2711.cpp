#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T,N;
	basic_string<char> bsc1;
	cin >> T;
	while (T--)
	{
		cin >> N >> bsc1;
		bsc1.erase(N-1, 1);
		cout << bsc1 << '\n';
	}
}

// solve