#include <bits/stdc++.h>
using namespace std;

bool not_empty(queue<int>& q1)
{
	if (q1.empty())
	{
		cout << -1 << '\n';
		return false;
	}
	else return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n{}, t{};
	string s1;
	queue<int> q1;
	vector<string> list = { "push","pop","size","empty","front","back" };
	cin >> n;
	while(n--)
	{
		cin >> s1;
		if(s1==list[0])
		{
			cin >> t;
			q1.push(t);
		}
		else if(s1==list[1] && not_empty(q1))
		{
			cout << q1.front() << '\n';
			q1.pop();
		}
		else if(s1==list[2])
		{
			cout << q1.size() << '\n';
		}
		else if(s1==list[3])
		{
			cout << q1.empty() << '\n';
		}
		else if(s1==list[4] && not_empty(q1))
		{
			cout << q1.front() << '\n';
		}
		else if(s1==list[5] && not_empty(q1))
		{
			cout << q1.back() << '\n';
		}
	}
}

// solve