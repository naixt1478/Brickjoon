#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int k,f;
	long long sum{};
	cin >> k;
	stack<int> st1;
	while (k--)
	{
		cin >> f;
		if (f == 0)
		{
			sum -= st1.top();
			st1.pop();
		}
		else
		{
			st1.push(f);
			sum += f;
		}
	}
	cout << sum;
}

// solve