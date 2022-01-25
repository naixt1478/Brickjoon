#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	bitset<10001> pbit;
	pbit.reset();
	for (int i = 2; i < pbit.size(); i++)
	{
		if (pbit[i]) continue;
		for (int j = 2 * i; j < pbit.size(); j += i)
		{
			pbit[j]=1;
		}
	}

	int t,n,a,b;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 2; i < pbit.size(); i++)
		{
			if (pbit[i] == 0)
			{
				if (i <= n - i && pbit[n - i] == 0)
				{
					a = i;
					b = n - i;
					continue;
				}
				else if (pbit[n - i]) continue;
				break;
			}
		}
		cout << a << ' ' << b << '\n';
	}
}

// solve