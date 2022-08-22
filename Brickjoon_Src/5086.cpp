#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	_FASTIOS;
	int a,b;
	while(cin >> a >> b,a!=0,b!=0)
	{
		if(b%a==0)
		{
			cout << "factor";
		}
		else if(a%b==0)
		{
			cout << "multiple";
		}
		else
		{
			cout << "neither";
		}
		cout << '\n';
	}
}

// solve
