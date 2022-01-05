// 4ms code
#include <bits/stdc++.h>
using namespace std;

void out(int s)
{
	cout << s << '\n';
}
bool dout(int s)
{
	if (s) out(-1);
	else return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,i,t;
	string str;
	deque <int> d1;
	cin >> n;
	while(n--)
	{
		cin >> str;
		t = d1.empty();
		if(str == "push_back")
		{
			cin >> i;
			d1.push_back(i);
		}
		else if (str == "push_front")
		{
			cin >> i;
			d1.push_front(i);
		}
		else if (str == "pop_front")
		{
			if (dout(t))
			{
				out(d1.front());
				d1.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (dout(t))
			{
				out(d1.back());
				d1.pop_back();
			}
		}
		else if (str == "size") out(d1.size());
		else if (str == "empty") out(t);
		else if (str == "front")
		{
			if (dout(t)) out(d1.front());
		}
		else if (str == "back")
		{
			if (dout(t)) out(d1.back());
		}
	}
}

// 0 ms code
/*
#include <bits/stdc++.h>
using namespace std;

void out(int s)
{
	cout << s << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,i;
	string str;
	deque <int> d1;
	cin >> n;
	while(n--)
	{
		cin >> str;
		if(str == "push_back")
		{
			cin >> i;
			d1.push_back(i);
		}
		else if (str == "push_front")
		{
			cin >> i;
			d1.push_front(i);
		}
		else if (str == "pop_front")
		{
			if (d1.empty()) out(-1);
			else
			{
				out(d1.front());
				d1.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (d1.empty()) out(-1);
			else
			{
				out(d1.back());
				d1.pop_back();
			}
		}
		else if (str == "size")
		{
			out(d1.size());
		}
		else if (str == "empty")
		{
			out(d1.empty());
		}
		else if (str == "front")
		{
			if (d1.empty()) out(-1);
			else out(d1.front());
		}
		else if (str == "back")
		{
			if (d1.empty()) out(-1);
			else out(d1.back());
		}
	}
}
*/

// solve
