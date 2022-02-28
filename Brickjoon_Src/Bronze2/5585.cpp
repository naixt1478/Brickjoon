#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int c,r{};
	vector<int> mod = { 500,100,50,10,5,1 };
	cin >> c;
	c = 1000 - c;
	for (int& m : mod)
	{
		r += c / m;
		c %= m;
	}
	cout << r;
}

// solve
