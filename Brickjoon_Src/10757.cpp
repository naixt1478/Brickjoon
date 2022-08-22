#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	string str,str2;
	cin >> str >> str2;
	int s1l = str.length(), s2l = str2.length();
	vector <int> s1(int(max(s1l, s2l) + 1));
	for (int i = 0; i < s1.size()-1; i++)
	{
		auto maxs1 = (0 + i);
		if (s1l - i > 0) s1[maxs1] += int(str[s1l - i-1] - '0');
		if (s2l - i > 0) s1[maxs1] += int(str2[s2l - i-1] - '0');
		if (s1[maxs1] >= 10)
		{
			s1[maxs1] %= 10;
			s1[maxs1 + 1]++;
		}
	}
	for (int i = s1.size() - 1; i >= 0; i--)
	{
		if (s1.size() - 1 == i and s1[i] == 0) continue;
		cout << s1[i];
	}
}
// solve !!!