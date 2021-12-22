#include <bits/stdc++.h>
using namespace std;

int stoc(char c)
{
	return (c - '0');
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n,b(0),c(0), d;
	string str;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		str = to_string(i);
		for (int j = 0; j < str.size(); j++)
		{
			if ((j + 1) >= str.size())
			{
				b++;
			}
			else
			{
				d = stoc(str[j]) - stoc(str[j + 1]);
				if(c == d || j == 0)
				{
					c = d;
				}
				else
				{
					break;
				}
			}
		}
	}
	cout << b;
}

// solved