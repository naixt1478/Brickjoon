#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, k;
	cin >> n;
	vector<int> ctp(n);
	for(int i = 0; i < n; i++)
	{
		cin >> ctp[i];
	}
	cin >> k;
	const int t = n / k;
	for(int i = 0; i < k; i++)
	{
		ranges::sort(ctp.begin() + t * i, ctp.begin() + t * (i + 1));
	}
	for(const int g : ctp)
	{
		cout << g << ' ';
	}
}

// solve