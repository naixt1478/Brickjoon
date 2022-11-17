#include <bits/stdc++.h>
using namespace std;
namespace rng = ranges;

int main()
{
	basic_string<char> bsc1;
	cin >> bsc1;
	for (auto& c1 : bsc1)
	{
		if (c1 >= 'a' && c1 <= 'z') c1 -= 32;
		else c1 += 32;
	}
	cout << bsc1;
}

// solve