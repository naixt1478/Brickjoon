#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << max(a + b, a - b) << '\n' << min(a + b, a - b);
}

// solve