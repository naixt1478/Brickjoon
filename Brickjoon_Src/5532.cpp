#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int l, a, b, c, d,r[3];
	cin >> l >> a >> b >> c >> d;
	r[0] = (a%c == 0 ? a/c : a/c + 1);
	r[1] = (b % d == 0 ? b / d : b / d + 1);
	cout << (l - max(r[0], r[1]));
}

// solve