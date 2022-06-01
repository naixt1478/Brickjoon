#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, a{}, b{};
	cin >> n;
	vector<int> sum(n);
	while(n--) cin >> sum[n];
	ranges::sort(sum);
	for(int& t : sum)
	{
		a += t;
		b += a;
	}
	cout << b;
}

// solve