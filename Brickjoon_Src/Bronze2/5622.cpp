#include <bits/stdc++.h>
using namespace std;

int match(char c)
{
	int a = 2, b;
	b = c - '@';
	if (b <= 15)
	{
		if (b % 3 != 0)a++;
		return b / 3 + a;
	}
	else if (b <= 19) return 6+a;
	else if (b <= 22) return 7+a;
	else return 8+a;
}

int main()
{
	int n = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		n += match(str.at(i));
	}
	cout << n;
}

// solve
