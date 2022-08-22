#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int N, max{}, t;
	cin >> N;
	N *= 2;
	while(N--)
	{
		cin >> t;
		max += abs(t);
	}
	cout << max;
}

// solve