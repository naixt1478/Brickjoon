#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, k, t{};
	cin >> n >> k;
	queue<int> q1, r1;
	for(int i = 1; i <= n; i++)
	{
		q1.push(i);
	}
	while(q1.empty() != 1)
	{
		t++;
		if(t==k)
		{
			r1.push(q1.front());
			q1.pop();
			t = 0;
		}
		else
		{
			q1.push(q1.front());
			q1.pop();
		}
	}
	cout << '<';
	while(r1.empty() != 1)
	{
		cout << r1.front() << (r1.size() == 1 ? ">" : ", ");
		r1.pop();
	}
}

// solve