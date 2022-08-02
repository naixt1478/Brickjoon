#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;
namespace rng = ranges;

int main()
{
	_FASTIOS
	basic_string<char> s;
	cin >> s;
	rng::sort(s,rng::greater());
	cout << s;
}

// solve