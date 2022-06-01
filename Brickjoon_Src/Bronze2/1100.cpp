#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
typedef basic_string<char> bsc;

int main()
{
	_FASTIOS;
	bsc bsc1;
	int i{},sum{},j{8};
	while(j--)
	{
		cin >> bsc1;
		for(auto& c1 : bsc1) if(i++ % 2 == 0 && c1 == 'F') sum++;
		i++;
	}
	cout << sum;
}

// solve