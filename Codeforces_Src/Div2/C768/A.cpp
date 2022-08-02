#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
	int t1,t2,c1,c2,c3,c4;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for(int i = 0; i < n; i++)
	{
		c1 = *max_element(a.begin(), a.end());
		c3 = *max_element(b.begin(), b.end());
		t1 = a[i];
		t2 = b[i];
		a[i] = t2;
		b[i] = t1;
		c2 = *max_element(a.begin(), a.end());
		c4 = *max_element(b.begin(), b.end());
		if(c1 < c2 || c3 < c4)
		{
			a[i] = t1;
			b[i] = t2;
		}
	}
	return *max_element(a.begin(), a.end()) * *max_element(b.begin(), b.end());
}

int main()
{
	int t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << solve(n) << '\n';
	}
}