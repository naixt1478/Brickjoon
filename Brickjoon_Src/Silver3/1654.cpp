#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli psearch(vector<int>& vec1, lli epos, const int& val, lli spos = 1)
{
	lli div_sum{ 0 }, mid = (spos + epos) / 2;
	for (auto& num : vec1)
	{
		div_sum += num / mid;
	}
	if (spos > epos) return mid;
	else if (div_sum >= val) return psearch(vec1, epos, val, mid + 1);
	else if (div_sum < val) return psearch(vec1, mid - 1, val, spos);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int k, n;
	cin >> k >> n;
	vector<int> num(k);
	for (auto& in : num)
	{
		cin >> in;
	}
	ranges::sort(num);
	cout << psearch(num, num[k - 1], n);
}
// solve
/*
 * while loop code
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli psearch(vector<int>& vec1,lli epos,const int& val,lli spos=1)
{
	lli mid, div_sum;
	while (spos <= epos)
	{
		mid = (spos + epos) / 2, div_sum = 0;
		for (auto& num : vec1)
		{
			div_sum += num / mid;
		}
		if (div_sum >= val) spos = mid + 1;
		else if (div_sum < val) epos = mid - 1;
	}
	return epos;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int k, n;
	cin >> k >> n;
	vector<int> num(k);
	for (auto& in : num)
	{
		cin >> in;
	}
	ranges::sort(num);
	cout << psearch(num, num[k-1], n);
}
*/
