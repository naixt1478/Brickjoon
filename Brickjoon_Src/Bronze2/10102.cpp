#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
template <typename T>
using bs = basic_string<T>;

int main()
{
	bs<char> bsc1;
	cin.ignore();
	cin >> bsc1;
	int A{}, B{};
	for (char c1 : bsc1)
	{
		if (c1 == 'A') A++;
		else B++;
	}
	cout << (A >= B ? (A == B ? "Tie" : "A") : "B");
}

// solve
