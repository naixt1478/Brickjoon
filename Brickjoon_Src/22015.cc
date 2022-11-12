#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, i1;
	cin >> a >> b >> c;
	if (a >= b && a >= c) i1 = a;
	else if (b >= a && b >= c) i1 = b;
	else if (c >= a && c >= b) i1 = c;
	cout << i1 - a + i1 - b + i1 - c;
}

// solve