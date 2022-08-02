#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	lli N,max1{},min1{};
	cin >> N;
	vector<lli> num(N);
	for (auto& n : num) cin >> n;
	for(lli i = 1; i < N-1; i++)
	{
		min1 = min(num[i - 1], num[i + 1]);
		if(min1 != 0) max1 = max(max1, (num[i] + min1));
	}
	cout << max1;
}