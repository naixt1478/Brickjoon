#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define pi 3.141592
using namespace std;

int main()
{
	_FASTIOS;
	double a, b;
	cin >> a >> b;
	cout << fixed << setprecision(6) << (b * 2 * pi + a * 2);
}

// solve