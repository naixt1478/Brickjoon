#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b{};
	vector<int> vi1;
	basic_string<char> bsc1;
	getline(cin, bsc1);
	stringstream ss2(bsc1);
	while (getline(ss2, bsc1, ':'))
	{
		stringstream ss3(bsc1);
		ss3 >> a;
		vi1.emplace_back(a);
	}
	for (int i = 0; i < 3; i++)
	{
		if (1 <= vi1[i] && vi1[i] <= 12)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i != j && 0 <= vi1[j] && vi1[j] <= 59 && 0 <= vi1[3 - i - j] && vi1[3 - i - j] <= 59) b++;
				else continue;
			}
		}
	}
	cout << b;
}

// solve