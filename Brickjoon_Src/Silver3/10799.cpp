#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
template<typename T>
using bs = basic_string<T>;

int main()
{
	__fastios;
	int sum1{}, now{};
	bs<char> bsc1;
	stack<char> sc1;
	cin >> bsc1;
	for (auto& c1 : bsc1)
	{
		if (c1 == '(')
		{
			sc1.push('(');
			now++;
		}
		else		
		{
			now--;
			if (sc1.top() == '(') sum1 += now;
			else sum1 += 1;
			sc1.push(')');
		}
	}
	cout << sum1;
}

// solve