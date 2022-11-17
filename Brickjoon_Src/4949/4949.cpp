#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s1;
	stack<char> st1;
	while(getline(cin, s1),s1 != ".")
	{
		auto clear = [](auto& st1) {stack<char> st2; st1.swap(st2); };
		clear(st1);
		for(auto& c : s1)
		{
			if (c == '[' || c == '(') st1.push(c);
			else if ((c == ']' || c == ')') && st1.empty())
			{
				st1.push(']');
				break;
			}
			else if (c == ']')
			{
				if (st1.top() == '[') st1.pop();
				else break;
			}
			else if (c == ')')
			{
				if (st1.top() == '(') st1.pop();
				else break;
			}
		}
		if (st1.empty()) cout << "yes\n";
		else cout << "no\n";
	}
}

// solve