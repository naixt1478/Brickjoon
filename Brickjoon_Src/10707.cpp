#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	if (e <= c)
		cout << (a*e < b ? a * e : b);
	else
		cout << (a*e < b+(e-c)*d ? a*e : b+(e-c)*d);
}

// solve