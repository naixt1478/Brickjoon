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
	int a(-1);
	for (int i = 1; i <= d2.size(); i++)
	{
		d1.at(d1.size() - i) += d2.at(d2.size() - i);
	}

	while(true)
	{
		if (d1.size() != 1 && d1[0] == 0)
		{
			d1.pop_front();
		}
		else
		{
			a++;
		}

		if (d1[d1.size() - 1 - a] / -10 >= 1)
		{
			if (d1.size() - 1 - a == 0)
			{
				d1.push_front(-(d1[d1.size() - 1 - a] / -10));
			}
			else
			{
				d1[d1.size() - 2 - a] -= d1[d1.size() - 1 - a] / -10;
			}
			d1[d1.size() - 1 - a] %= -10;
		}
		else if (d1[d1.size() - 1 - a] / 10 >= 1)
		{
			if (d1.size()-1-a == 0)
			{
				d1.push_front(d1[d1.size()-1-a] / 10);
			}
			else
			{
				d1[d1.size() - 2 - a] += d1[d1.size() - 1 - a] / 10;
			}
			d1[d1.size()-1-a] %= 10;
		}
		else if (a == d1.size() - 1)
		{
			break;
		}
		else if (d1[0 + a] > 0 && d1[1 + a] < 0)
		{
			d1[0 + a]--;
			d1[1 + a] += 10;
		}
		else if (d1[0 + a] < 0 && d1[1 + a] >= 0)
		{
			for (int i = 1 + a; i < d1.size(); i++)
			{
				if (d1[i] != 0)
				{
					d1[0 + a]++;
					d1[1 + a] += -10;
					break;
				}
			}
		}
	}

	for (int i = 0; i < d1.size(); i++)
	{
		if (i == 0) cout << d1.at(i);
		else cout << abs(d1.at(i));
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

/* π›∑ 
* 9876543210 -1234567890 
* æ∆«≤ : 8642024680
* ¡§¥‰ : 8641975320
* ≥ª¿œ «»Ω∫
*/ 

// solve in progress
