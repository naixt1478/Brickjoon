#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0);
using namespace std;
namespace rng = ranges;
typedef long long int lli;

int ctoi(char& c)
{
	return c - '0';
}

int main()
{
	int sum{},temp{};
	char tri = '+';
	basic_string<char> s1;
	cin >> s1;
	for(auto& c : s1)
	{
		if(c != '+' && c != '-')
		{
			temp = (temp * 10) + ctoi(c);
		}
		else if(tri == '-')
		{
			tri = '-';
			sum -= temp;
			temp = 0;
		}
		else
		{
			sum += temp;
			temp = 0;
			if (c == '-') tri = '-';
		}
	}
	if (tri == '-') sum -= temp;
	else sum += temp;

	cout << sum;
}

// solve