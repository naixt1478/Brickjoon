#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;
namespace rng = ranges;

void hanoi(int now,int next,int n)
{
	if (n == 1) cout << now << ' ' << next << '\n';
	else
	{
		const int next_empty = 6 - (now + next);
		hanoi(now, next_empty, n - 1);
		cout << now << ' ' << next << '\n';
		hanoi(next_empty, next, n - 1);
	}
}

int pow2i(int n)
{
	if (n == 1) return 2;
	return pow2i(n - 1) * 2;
}

int main()
{
	_FASTIOS
	int a{1}, b{3}, n;
	cin >> n;
	cout << pow2i(n) - 1 << '\n';
	hanoi(a,b,n);
}

// solve