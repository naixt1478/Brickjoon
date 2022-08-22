#include <bits/stdc++.h>
using namespace std;

int ch_temp = 0;

void stoi_deq(deque<int> & deq, string s1)
{
	for(int i = 0 + (s1[0] == '-'); i < s1.size(); i++)
	{
		deq.push_back((s1[0] == '-' ? (-(s1[i] - '0')) : (s1[i] - '0')));
	}
}

void swap_large_str(string* left,string* right)
{
	string temp;
	string str1 = *left, str2 = *right;
	if (str1[0] == '-') str1.erase(0, 1);
	if (str2[0] == '-') str2.erase(0, 1);

	if (str1.length() < str2.length())
	{
		swap(*left, *right);
	}
	else if (str1.length() == str2.length())
	{
		if(str1 < str2)
		{
			swap(*left, *right);
		}
	}
}

void req_sp(deque<int>& deq, int b, int index, int tri)
{
	int temp;
	if (deq[0] < 0)
	{
		if (tri == 1)
		{
			if (deq[deq.size() - index] + b > 0)
			{
				deq[deq.size() - index - 1]++;
				deq[deq.size() - index] += b;
				deq[deq.size() - index] = -(10 - deq[deq.size() - index]);
				req_sp(deq, 0, index + 1, 1);
			}
			else
			{
				deq[deq.size() - index] += b;
			}
		}
	}
	else
	{
		if (tri == 0)
		{
			if (deq[deq.size() - index] + b < 0)
			{
				deq[deq.size() - index - 1]--;
				deq[deq.size() - index] += b;
				deq[deq.size() - index] += 10;
				req_sp(deq, 0, index + 1, 0);
			}
			else
			{
				deq[deq.size() - index] += b;
			}
		}
	}
}

void req_plus(deque<int>& vec,int b,int index)
{
	if (ch_temp == true) return req_sp(vec, b, index, 1);
	vec[vec.size() - index] += b;
	if(vec[vec.size() - index] > 9)
	{
		if(vec.size() - index == 0)
		{
			int temp = vec[vec.size() - index];
			vec[vec.size() - index] %= 10;
			vec.push_front(temp / 10);
			return;
		}
		vec[vec.size() - index - 1] += vec[vec.size() - index] / 10;
		vec[vec.size() - index] %= 10;
		req_plus(vec, 0, index + 1);
	}
}

void req_minus(deque<int>& deq,int b,int index)
{
	if (ch_temp == true) return req_sp(deq, b, index, 0);
	int temp;
	if(abs(deq[deq.size() - index]) + abs(b) > 9)
	{
		if(deq.size() - index == 0)
		{
			temp = abs(deq[deq.size() - index]) + abs(b);
			deq[deq.size() - index] = -(temp % 10);
			deq.push_front(-temp / 10);
			return;
		}
		temp = abs(deq[deq.size() - index]) + abs(b);
		deq[deq.size() - index - 1] = -abs(deq[deq.size() - index - 1]) - (temp / 10);
		deq[deq.size() - index] = -(temp % 10);
		req_minus(deq, 0, index + 1);
	}
	else
	{
		deq[deq.size() - index] = -abs(deq[deq.size() - index]) - abs(b);
	}
}

void solve_sp(string s1, string s2)
{
	
	swap_large_str(&s1, &s2);
	deque<int> a,b;
	if (s1[0] == '-' && s2[0] != '-') ch_temp = 1;
	if (s1[0] != '-' && s2[0] == '-') ch_temp = 1;
	stoi_deq(a, s1);
	stoi_deq(b, s2);
	for(int i = b.size(); i > 0; i--)
	{
		if (b[b.size() - i] >= 0)
		{
			req_plus(a, b[b.size() - i], i);
		}
		else
		{
			req_minus(a, b[b.size() - i], i);
		}
		while(a[0]==0 && a.size() != 1)
		{
			a.pop_front();
		}
	}

	for(int i = 0; i < a.size(); i++)
	{
		if (i == 0) cout << a[i];
		else cout << abs(a[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	string num1, num2;
	cin >> num1 >> num2;
	solve_sp(num1, num2);
}

// solve