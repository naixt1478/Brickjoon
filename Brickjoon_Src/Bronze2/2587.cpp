#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges; 

int main()
{
	__fastios;
	int sum1{};
	vector<int> vi1(5);
	for (int& i1 : vi1)
	{
		cin >> i1;
		sum1 += i1;
	}
	rng::sort(vi1);
	cout << sum1 / 5 << '\n' << vi1[2];
}

// solve