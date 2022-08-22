#include <bits/stdc++.h>
using namespace std;

int main()
{
	deque <string> s = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string str;
	cin >> str;
	for (int i = 0; i < s.size(); i++)
	{
		while (str.find(s[i]) != string::npos)
		{
			int pos = str.find(s[i]);
			str.replace(pos,s[i].length(), "*");
		}
	}
	cout << str.length();
}

// solve