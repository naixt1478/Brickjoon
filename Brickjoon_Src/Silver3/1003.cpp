#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0);
using namespace std;
typedef long long int lli;

vector<lli> memo(42);

lli fibo(lli n)
{
	if(n < 2) return n ^ 1;
	else if(memo[n] ^ 0) return memo[n];
	else
	{
		memo[n] = fibo(n - 1) + fibo(n - 2);
		return memo[n];
	}
}

int main()
{
	_FASTIOS
	lli N,T;
	cin >> N;
	while(N--)
	{
		cin >> T;
		cout << fibo(T) << ' ' << fibo(T+1) << '\n';
	}
}

// solve