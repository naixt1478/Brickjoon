#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cout.tie(nullptr),cin.tie(nullptr)
using namespace std;

int main()
{
	__fastios;
	int n,r{};
	cin >> n;
	if(n%4 > 0)
	{
		r = n / 4 + 1;	
	}
	else
	{
		r = n / 4;
	}
	if(r%2 == 0)
	{
		cout << 6 - (n - ((r - 1) * 4));
	}
	else
	{
		cout << (n - ((r - 1) * 4));
	}
}

// solve