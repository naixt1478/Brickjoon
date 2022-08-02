#include <bits/stdc++.h>
using namespace std;

int over = 0;

void stoi(string s,deque<int>& mdeq, char c = '+')
{
	if(c=='+')
	{
		for(int i = 0; i < s.size(); i++)
		{
			mdeq.push_back(s[i] - '0');
		}
	}
	else
	{
		for(int i = 0; i < s.size(); i++)
		{
			mdeq.push_back(-(s[i] - '0'));
		}
	}
}

void BG_sp(deque<int>&deq, int b, int index)
{
	if (deq[deq.size() - index] + b < 0)
	{
		if(deq.size() - index == 0)
		{
			deq[deq.size() - index] += b;
			deq[deq.size() - index] += 10;
			over = 1;
			return;
		}
		deq[deq.size() - index - 1]--;
		deq[deq.size() - index] += b;
		deq[deq.size() - index] += 10;
		BG_sp(deq, 0, index + 1);
	}
	else
	{
		deq[deq.size() - index] += b;
	}
}

int main()
{
	long long count{};
	string s1, s2, s3;
	deque<int> a, b, c;
	cin >> s1 >> s2 >> s3;
	stoi(s1, a, '-');
	stoi(s2, b);
	stoi(s3, c, '-');
	for(int i = c.size(); i > 0; i--)
	{
		BG_sp(b, c[c.size() - i], i);
		while(b[0] == 0 && b.size() != 1)
		{
			b.pop_front();
		}
	}
	while (b.size() != 1 || b[0] != 0 || b.size() >= a.size() || over==0)
	{
		for (int i = a.size(); i > 0; i--)
		{
			BG_sp(b, a[a.size() - i], i);
			if (over == 1) break;
			while (b[0] == 0 && b.size() != 1)
			{
				b.pop_front();
			}
		}
		if (over == 1) break;
		count++;
	}
	cout << count;
}

// stop in solve