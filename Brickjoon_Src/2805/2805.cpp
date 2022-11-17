#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli psearch(vector<int>& vec1, lli epos, const int& val, lli spos = 1)
{
	lli div_sum{ 0 }, mid = (spos + epos) / 2;
	for (auto& num : vec1)
	{
		div_sum += (num < mid ? 0 : num-mid);
	}
	if (spos > epos) return mid;
	else if (div_sum >= val) return psearch(vec1, epos, val, mid + 1);
	else if (div_sum < val) return psearch(vec1, mid - 1, val, spos);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> num(n);
	for (auto& in : num)
	{
		cin >> in;
	}
	ranges::sort(num);
	cout << psearch(num, num[n - 1], m);
}

// solve