#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int A, B, C;
	while(cin >> A >> B >> C)
	{
		cout << max((B - A), (C - B)) - 1 << '\n';
	}
}

// solve