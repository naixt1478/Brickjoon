#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n;
	stack <int> s;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		bool r = true;
		cin >> str;
		int b = str.length();
		for (int j = 0; j < b; j++)
		{
			if (str.at(j) == '(')
				s.push(1);
			else if (str.at(j) == ')')
				if (s.empty() == 0)
					s.pop();
				else
				{
					r = false;
					break;
				}
		}
		if (s.empty() == 0)
			r = false;

		while (s.empty() == 0)
			s.pop();

		if (r == true)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}

// solved