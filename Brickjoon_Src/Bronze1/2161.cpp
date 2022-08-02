#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	cin >> n;
	queue<int> q1;
	for (int i = 1; i <= n; i++)
	{
		q1.push(i);
	}
	while (1) 
	{
		cout << q1.front() << ' ';
		q1.pop();
		if (q1.empty()) break;
		q1.push(q1.front());
		q1.pop();
	}
}

// solve