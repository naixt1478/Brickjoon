#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	long long n, buf, b = 0, f = 1;
	cin >> n;
	for (long long i = 1; i < n; i++)
	{
		buf = b + f;
		b = f;
		f = buf;
	}
	cout << f*2+(f+b)*2;
}

// solve
// ��-��-�� �Ǻ���ġ