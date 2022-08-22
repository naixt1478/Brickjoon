#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

void up(basic_string<char> & bsc)
{
	long long int i = 0;
	bsc[bsc.length() - 1]++;
	while(true)
	{
		i++;
		if(bsc.length() - i >= 0)
		{
			if (bsc[bsc.length() - i] > '9')
			{
				bsc[bsc.length() - i] = '0';
				if (static_cast<long long int>(bsc.length()) - i - 1 < 0)
				{
					bsc.insert(0, "1");
					break;
				}
				else bsc[static_cast<long long int>(bsc.length()) - i - 1]++;
			}
			else break;
		}
	}
}

void subtract(basic_string<char> & num,basic_string<char> & sub)
{
	for(long long int i = 0; i < sub.length(); i++)
	{
		long long int j = 0;
		num[num.length() - i - 1] -= sub[sub.length() - i - 1] - '0';
		while(true)
		{
			j++;
			if (num[num.length() - i - j] < '0')
			{
				num[num.length() - i - j] += 10;
				num[num.length() - i - j - 1]--;
			}
			else break;
		}
	}
	while(num.length()>1)
	{
		if (num.front() == '0') num.erase(0, 1);
		else break;
	}
}

int main()
{
	__fastios;
	basic_string<char> bsc1,bsc2,bsc3 = "0";
	cin >> bsc1 >> bsc2;
	while(bsc1 >= bsc2)
	{
		up(bsc3);
		subtract(bsc1, bsc2);
	}
	cout << bsc3 << '\n' << bsc1;
}