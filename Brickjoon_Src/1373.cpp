#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
template <typename T>
using bs = basic_string<T>;

int main()
{
	_FASTIOS;
	int num{};
	bs<char> bsc1,bsc2;
	cin >> bsc1;
	size_t bsc1l = bsc1.length();
	for(int i = 0; i < bsc1l; i++)
	{
		if((bsc1l-i)%3==0 && bsc1[i]=='1') num += 4;
		else if((bsc1l-i)%3==2 && bsc1[i]=='1') num += 2;
		else if((bsc1l-i)%3==1)
		{
			if (bsc1[i] == '1') num += 1;
			bsc2.push_back(num+'0');
			num = 0;
		}
	}
	cout << bsc2;
}

// solve