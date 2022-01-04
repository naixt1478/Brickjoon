#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string str;
	float r(0.0);
	cin >> str;
	r += 'E' - str[0];
	if (r > 0) r += (str[1] < '0' ? (str[1] < '-' ? 0.3 : -0.3) : 0);
	else r = 0;
	cout << fixed << setprecision(1) << r;
}

// solve