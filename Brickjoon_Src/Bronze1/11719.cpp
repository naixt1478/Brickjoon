#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	string str;
	vector<string> s;
	while (getline(cin, str)) s.push_back(str);
	for(int i = 0; i < s.size(); i++)
	{
		cout << s[i] << '\n';
	}
}

// solve