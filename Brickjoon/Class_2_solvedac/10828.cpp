#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int n, i;
	ios::sync_with_stdio(false);
	stack <string> s;
	cin >> n;
	string c = { 0 };
	for (i = 0; i < n; i++)
	{
		cin >> c;
		if (c == "push")
		{
			cin >> c;
			s.push(c);
		}
		else if (c == "top")
		{
			if (s.empty() == 0)
				cout << s.top() << "\n";
			else
				cout << "-1" << "\n";
		}
		else if (c == "size")
		{
			cout << s.size() << "\n";
		}
		else if (c == "empty")
		{
			cout << s.empty() << "\n";
		}
		else if (c == "pop")
		{
			if (s.empty() == 0)
			{
				cout << s.top() << "\n";
				s.pop();
			}
			else
				cout << "-1" << "\n";
		}
		c = { 0 };
	}
}

// solved