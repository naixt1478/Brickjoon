#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
	_FASTIOS;
	double L;
	cin >> L;
	cout << fixed << setprecision(9) << L * L * sqrt(3) / 4;
}

// solve