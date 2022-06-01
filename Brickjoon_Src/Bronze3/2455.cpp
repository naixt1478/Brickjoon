#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
	_FASTIOS;
	int max1{},now1{},a,b,n{4};
	while(n--)
	{
		cin >> a >> b;
		now1 += b - a;
		if(now1 > max1) max1 = now1;
	}
	cout << max1 << '\n';
}

// solve
