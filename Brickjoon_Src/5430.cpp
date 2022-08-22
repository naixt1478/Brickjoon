#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int t, n, r{}, err{}, rev{};
	string s1, s2, s3;
	cin >> t;
	deque<int> deq1;
	while (t--)
	{
		err = 0, r = 0, rev = 0;
		deq1.clear();
		cin >> s1 >> n;
		cin >> s2;
		s2.erase(s2.size() - 1, 1);
		s2.erase(0, 1);
		stringstream ss1(s2);
		while (getline(ss1, s3, ','))
		{
			stringstream ss2(s3);
			ss2 >> n;
			deq1.emplace_back(n);
		}
		for (auto& a : s1)
		{
			if (a == 'R')
			{
				rev ^= 1;
			}
			else if (deq1.empty() != 1)
			{
				if (rev == 1) deq1.pop_back();
				else deq1.pop_front();
			}
			else
			{
				err = 1;
				break;
			}
		}
		r = deq1.size();
		if (rev == 1) ranges::reverse(deq1);
		if (err == 1) cout << "error" << '\n';
		else
		{
			cout << '[';
			for (auto& c : deq1)
			{
				cout << c;
				if (--r != 0) cout << ',';
			}
			cout << "]\n";
		}
	}
}

// solve