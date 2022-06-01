#include <bits/stdc++.h>
using namespace std;

struct pos
{
	int s, m, e;
};

int solve(int a, int b, vector<int>& vec, int find)
{
	pos u{a,0,b}, l{a,0,b};
	while(u.e > u.s || l.e > l.s)
	{
		if (l.e > l.s)
		{
			l.m = (l.s + l.e) / 2;
			if (vec[l.m] < find) l.s = l.m + 1;
			else l.e = l.m;
		}
		if (u.e > u.s)
		{
			u.m = (u.s + u.e) / 2;
			if (vec[u.m] <= find) u.s = u.m + 1;
			else u.e = u.m;
		}
	}
	return u.e - l.s;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, m, r;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	cin >> m;
	ranges::sort(num.begin(), num.end());
	for (int i = 0; i < m; i++)
	{
		cin >> r;
		cout << solve(0,n,num,r) << ' ';
	}
}

// solve

/* C++ STL USING CODE
 *
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,m;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	cin >> m;
	vector<int> num2(m);
	for (int i = 0; i < m; i++)
	{
		cin >> num2[i];
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < m; i++)
	{
		cout << upper_bound(num.begin(), num.end(), num2[i]) - lower_bound(num.begin(), num.end(), num2[i]) << ' ';
	}
}
 *
 */