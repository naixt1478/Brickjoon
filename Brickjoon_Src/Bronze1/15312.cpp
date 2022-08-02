#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	string s1, s2;
	cin >> s1 >> s2;
	vector<int> num, c = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
	for(int i = 0; i < s1.size(); i++)
	{
		num.emplace_back(c[s1[i] - 'A']);
		num.emplace_back(c[s2[i] - 'A']);
	}
	while(num.size()!=2)
	{
		for(int i = 0; i < num.size()-1; i++)
		{
			num[i] = (num[i] + num[i + 1]) % 10;
		}
		num.pop_back();
	}
	cout << num[0] << num[1];
}

// solve