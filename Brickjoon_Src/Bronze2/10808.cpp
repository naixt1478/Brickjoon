#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	_FASTIOS;
	vector<int> check(26);
	basic_string<char> bsc1;
	cin >> bsc1;
	for(auto& c1 :bsc1) check[c1 - 'a']++;
	for (auto& n1 : check) cout << n1 << ' ';
}

// solve