#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, sum1{}, l{}, t;
	cin >> N;
	while (N--)
	{
		cin >> t;
		if (t == 1) l++;
		else l = 0;
		sum1 += l;
	}
	cout << sum1;
}

// solve