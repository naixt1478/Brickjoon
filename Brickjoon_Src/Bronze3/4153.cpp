#include <bits/stdc++.h>
using namespace std;

int powi(int n)
{
	return n * n;
}

void out(string s)
{
	cout << s << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	vector<int> num(3);
	while (cin >> num[0] >> num[1] >> num[2])
	{
		sort(num.begin(), num.end());
		if (num[2] == 0) break;
		if (powi(num[0]) + powi(num[1]) == powi(num[2])) out("right");
		else out("wrong");
	}
}

// solve
