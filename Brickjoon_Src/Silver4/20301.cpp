#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, k, m, i{0}, i2{0}, r{0};
	cin >> n >> k >> m;
	deque<int> d1(n);
	for(int i = 1; i <= n; i++)
	{
		d1[i - 1] = i;
	}
	while(d1.empty()!=1)
	{
		i2 = k-1;
		if(i >= m)
		{
			i = 0;
			r ^= 1;
		}
		else if (!r)
		{
			while(i2--)
			{
				d1.emplace_back(d1.front());
				d1.pop_front();
			}
			cout << d1.front() << '\n';
			d1.pop_front();
			i++;
		}
		else
		{
			while(i2--)
			{
				d1.emplace_front(d1.back());
				d1.pop_back();
			}
			cout << d1.back() << '\n';
			d1.pop_back();
			i++;
		}
	}
}

// solve