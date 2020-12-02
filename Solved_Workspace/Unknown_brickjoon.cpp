#include <iostream>
#include <string>
#include <vector>

using namespace  std;

int main()
{
	string s;
	cin >> s;
	vector<int> d(28);
	int a = 0, b = 0, c = 0;
	for (int i = 97; i < 123; i++)
	{
		a = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == i)
				d[i - 97]++;
			if (s[j] == i - 32)
				d[i - 97]++;
		}
	}
	a = d[0];
	for (int j = 1; j < 26; j++)
	{
		if (d[j] > a)
		{
			a = d[j];
			b = j;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (a == d[i])
			c++;
	}
	if (c > 1)
		cout << "?";
	else
		cout << char(b + 65);
}