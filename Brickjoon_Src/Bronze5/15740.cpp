#include <bits/stdc++.h>
using namespace std;

int ctoi(char c)
{
	return c - '0';
}

void ch_sign1(deque<int>& deq, string& str)
{
	if (str[0] == '-')
	{
		for (int i = 1; i < str.size(); i++)
		{
			deq.push_back(-ctoi(str[i]));
		}
	}
	else
	{
		for (int i = 0; i < str.size(); i++)
		{
			deq.push_back(ctoi(str[i]));
		}
	}
}

void solve(deque<int>& d1, deque<int>& d2)
{
	int a(0);
	for (int i = 1; i <= d2.size(); i++)
	{
		d1.at(d1.size() - i) += d2.at(d2.size() - i);
	}

	while(true)
	{
		if (d1[0+a] == 0)
		{
			d1.pop_front();
		}
		else if (a == d1.size() - 1)
		{
			break;
		}
		else if (1 + a == d1.size() - 1)
		{
			break;
		}
		else if (d1[0 + a] > 0 && d1[1 + a] < 0)
		{
			d1[0 + a]--;
			d1[1 + a] += 10;
		}
		else 
		{
			a++;
		}
	}

	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << ' ';
	}
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	deque<int> d1, d2;
	string s1,s2;
	cin >> s1 >> s2;
	ch_sign1(d1, s1);
	ch_sign1(d2, s2);
	if (d1.size() >= d2.size())
	{
		solve(d1, d2);
	}
	else
	{
		solve(d2, d1);
	}
}