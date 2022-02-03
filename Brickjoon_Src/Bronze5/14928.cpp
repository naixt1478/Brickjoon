#include <bits/stdc++.h>
using namespace std;

int ctoi(const char &c)
{
	return c - '0';
}

int main()
{
	string n;
	cin >> n;
	int mod = 20000303, result{};
	for(int i = 0; i < n.length(); i++)
	{
		result = (result * 10 + ctoi(n[i])) % mod;
	}
	cout << result;
}

// solve