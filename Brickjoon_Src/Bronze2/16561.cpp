#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	cin >> n;
	n /= 3;
	n--;
	cout << (n * n - n) / 2;
}

// solve