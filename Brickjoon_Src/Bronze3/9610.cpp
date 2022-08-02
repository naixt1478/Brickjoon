#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
template <typename T>
using bs = basic_string<T>;

struct Q
{
	bs<char> bsc1;
	int i{};
};

int main()
{
	int n, x, y;
	vector<Q> vQ1 = {Q("Q1"),Q("Q2"),Q("Q3"),Q("Q4"),Q("AXIS")};
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		if (x > 0 && y > 0) vQ1[0].i++;
		else if (x < 0 && y > 0) vQ1[1].i++;
		else if (x < 0 && y < 0) vQ1[2].i++;
		else if (x > 0 && y < 0) vQ1[3].i++;
		else vQ1[4].i++;
	}
	for (auto& [bsc1, i] : vQ1) cout << bsc1 << ": " << i << '\n';
}

// solve
