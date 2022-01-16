#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<char> value;
	char bf;
	int r = 0;
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	string str;
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		value.clear();
		cin >> str;
		bf = str[0];
		for (size_t j = 0; j < str.size(); j++)
		{
			if (bf == str[j])
			{
				bf = str[j];
				value.insert(str[j]);
			}
			else if (bf != str[j] && value.find(str[j]) == value.end())
			{
				bf = str[j];
				value.insert(str[j]);
			}
			else
			{
				r--;
				break;
			}
		}
		r++;
	}
	cout << r;
}

// solve