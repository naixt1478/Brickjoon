#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	__fastios;
	int t, sum{}, m1, p1;
	basic_string<char> bsc1;
	vector<int> a(26),b(26);
	cin >> t;
	cin >> bsc1;
	for (auto& c1 : bsc1) a[c1 - 'A']++;
	for (int i = 0; i < t-1; i++)
	{
		m1 = 0, p1 = 0;
		cin >> bsc1;
		vector<int>(26).swap(b);
		for (auto& c1 : bsc1) b[c1 - 'A']++;
		for (int j = 0; j < 26; j++)
		{
			if (a[j] == b[j] - 1)
			{
				if (p1 == true && m1 == false) m1 = true;
				else if (m1 == false) m1 = true;
				else
				{
					sum--;
					break;
				}
			}
			else if (a[j] == b[j] + 1)
			{
				if (m1 == true && p1 == false) p1 = true;
				else if (p1 == false) p1 = true;
				else
				{
					sum--;
					break;
				}
			}
			else if (a[j] != b[j])
			{
				sum--;
				break;
			}
		}
		sum++;
	}
	cout << sum;
}

// solve