#include <bits/stdc++.h>
using namespace std;

bool comp(string& a, string& b)
{
	if (a.length() != b.length())
	{
		return a.length() < b.length();
	}
	else
	{
		return a < b;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<string> str(n);
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	sort(str.begin(), str.end(), comp);
	for (int i = 0; i < n; i++)
	{
		if (i != 0 && str[i - 1] == str[i]) continue;
		cout << str[i] << '\n';
	}
}

// solve