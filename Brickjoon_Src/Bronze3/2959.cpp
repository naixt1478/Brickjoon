#include <bits/stdc++.h>
using namespace std;

int main()
{
	int c=4;
	vector<int> a(4);
	while (c--) cin >> a[c];
	ranges::sort(a);
	cout << a[0] * a[2];
}

// solve