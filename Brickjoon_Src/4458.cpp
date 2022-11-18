#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
	__fastios;
	int n;
	basic_string<char> bsc1;
	cin >> n;
	cin.ignore();
	while (n--) 
	{
		getline(cin,bsc1);
		if ('a' <= bsc1[0] && bsc1[0] <= 'z') bsc1[0] -= 32;
		cout << bsc1 << '\n';
	}
}

// solve