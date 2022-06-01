#include <bits/stdc++.h>
using namespace std;
namespace rng = ranges;
typedef long long int lli;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	lli N, M, B, B2{}, min1{ 256 }, max1{}, sum1{}, sum2{},h{},t{};
	cin >> N >> M >> B;
	vector<int> count(257);
	for (lli i = 0; i < N * M; i++)
	{
		cin >> t;
		count[t]++;
		min1 = rng::min(min1, t);
		max1 = rng::max(max1, t);
	}
	for(int i = min1; i <= max1; i++)
	{
		B2 = B,sum2 = 0,t = 0;
		for(auto& cnt : count)
		{
			if (cnt == 0)
			{
				t++;
				continue;
			}
			else if(i > t)
			{
				sum2 -= (t - i) * cnt;
				B2 += (t - i) * cnt;
			}
			else if(i < t)
			{
				sum2 += (t - i) * cnt * 2;
				B2 += (t - i) * cnt;
			}
			t++;
		}
		if (min1 == i)
		{
			sum1 = sum2;
			h = i;
		}
		else if (B2 >= 0 && sum1 >= sum2)
		{
			sum1 = sum2;
			h = i;
		}
	}
	cout << sum1 << ' ' << h;
}

// count solve
// solve
// 2D array brute solve
/*
 *#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> vi;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	lli N, M, B, B2{}, min1{ 256 }, max1{}, sum1{}, sum2{},h{};
	cin >> N >> M >> B;
	vector<vi> vv1(N, vi(M));
	for(auto& v1 : vv1)
	{
		for(auto& Mi : v1)
		{
			cin >> Mi;
			if (Mi < min1) min1 = Mi;
			if (Mi > max1) max1 = Mi;
		}
	}
	for(int i = min1; i <= max1; i++)
	{
		B2 = B,sum2 = 0;
		for(auto& v1 : vv1)
		{
			for(auto& Mi : v1)
			{
				if(Mi - i >= 0)
				{
					sum2 += (Mi - i) * 2;
					B2 += (Mi-i);
				}
				else
				{
					B2 += (Mi - i);
					sum2 += abs(Mi - i);
				}
			}
		}

		if (min1 == i)
		{
			sum1 = sum2;
			h = i;
		}
		else if (B2 >= 0 && sum1 >= sum2)
		{
			sum1 = sum2;
			h = i;
		}
	}

	cout << sum1 << ' ' << h;
}
 *
 */
