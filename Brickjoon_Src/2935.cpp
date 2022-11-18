#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
typedef basic_string<char> bsc;

int main()
{
	_FASTIOS;
	bsc a, b;
	char t;
	cin >> a >> t >> b;
	if(t == '+')
	{
		if (b.length() > a.length()) rng::swap(a, b);
		if (b.length() == a.length()) a[0] = '2';
		else a[a.length() - b.length()] = '1';
	}
	else
	{
		if (b.length() > a.length()) rng::swap(a, b);
		for (int i = 1; i < b.length(); i++) a.push_back('0');
	}
	cout << a;
}

// solve