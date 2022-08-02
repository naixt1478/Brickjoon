#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,max{},i,r{};
	cin >> n;
	stack<int> num;
	while(n--)
	{
		cin >> i;
		num.push(i);
	}
	while(num.empty()!=1)
	{
		if (max < num.top())
		{
			max = num.top();
			r++;
		}
		num.pop();
	}
	cout << r;
}

// solve