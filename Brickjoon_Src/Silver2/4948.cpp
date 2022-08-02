#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int t, n;
	bitset<246913> pbit;
	pbit.reset();
	for (int i = 2; i < pbit.size(); i++)
	{
		if (pbit[i] == 1) continue;
		for (int j = 2 * i; j < pbit.size(); j += i)
		{
			pbit[j] = 1;
		}
	}

	while (cin >> n)
	{
		t = 0;
		if (n == 0) break;
		for (int i = n+1; i <= n * 2; i++)
		{
			if (pbit[i] == 0) t++;
		}
		cout << t << '\n';
	}
}

// solve
// 에라스토테네스의 체 이용