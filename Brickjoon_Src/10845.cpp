#include <iostream>
#include <queue>
#include <string>

using namespace std;

void print1(int a)
{
	cout << a << "\n";
}
void print2()
{
	cout << "-1" << "\n";
}

int main()
{
	int n, a;
	ios::sync_with_stdio(false);
	string str;
	queue<int> q;
	cin >> n;
	while (n--)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> a;
			q.push(a);
		}
		if (str == "front")
		{
			if (q.empty() == 0)
				print1(q.front());
			else
				print2();
		}
		if (str == "back")
		{
			if (q.empty() == 0)
				print1(q.back());
			else
				print2();
		}
		if (str == "size")
			print1(q.size());
		if (str == "pop")
		{
			if (q.empty() == 0)
			{
				print1(q.front());
				q.pop();
			}
			else
				print2();
		}
		if (str == "empty")
			print1(q.empty());
	}
}

// solve