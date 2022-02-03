#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pmod(ll a,ll b,ll c)
{
	if (b == 0) return 1;
	return (pmod(a, b - 1, c)%c * a) % c;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	ll L, hash{};
	const ll r = 31, mod = 1234567891;
	cin >> L;
	string str;
	cin >> str;
	for(int i = 0; i < L; i++)
	{
		hash = (hash + ((str[i]-'`') * pmod(r,i,mod)) % mod) % mod;
	}
	cout << hash;
}

// solve