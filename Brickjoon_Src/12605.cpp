#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int N,i{};
	string s1,s2;
	cin >> N;
	cin.ignore();
	stack<string> st1;
	while (i++ < N)
	{
		getline(cin, s1);
		stringstream ss1(s1);
		while(ss1 >> s2) st1.push(s2);
		cout << "Case #" << i << ": ";
		while(!st1.empty())
		{
			cout << st1.top() << ' ';
			st1.pop();
		}
		cout << '\n';
	}
}

// solve