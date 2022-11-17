#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
using lli = long long int;

int main()
{
	__fastios;
	lli lli1;
	cin >> lli1;
	cout << static_cast<lli>(ceill(sqrtl(lli1)));
}

// solve