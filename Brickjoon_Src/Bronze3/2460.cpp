#include <bits/stdc++.h>
#define _fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	_fastios;
	int now1{}, max1{}, r1{10}, a, b;
	while (r1--)
	{
		cin >> a >> b;
		now1 += b;
		now1 -= a;
		if (now1 > max1) max1 = now1;
	}
	cout << max1;
}

// solve