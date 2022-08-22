#include <bits/stdc++.h>
using namespace std;

void SClear(stack<int> &s1)
{
	stack<int> s2;
	s1.swap(s2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, m, t, t2, b{0};
	stack<int> s1;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		SClear(s1);
		cin >> t;
		s1.push(n);
		while(t--)
		{
			cin >> t2;
			if (s1.top() < t2) b = 1;
			s1.push(t2);
		}
	}
	if (b == 0) cout << "Yes";
	else cout << "No";
}

// solve