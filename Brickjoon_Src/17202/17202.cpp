#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	string s1, s2;
	cin >> s1 >> s2;
	vector<int> num;
	for (int i = 0; i < 8; i++)
	{
		num.emplace_back(s1[i] - '0');
		num.emplace_back(s2[i] - '0');
	}
	while (num.size() != 2)
	{
		for (int i = 0; i < num.size() - 1; i++)
		{
			num[i] = (num[i] + num[i + 1]) % 10;
		}
		num.pop_back();
	}
	cout << num[0] << num[1];
}

// solve