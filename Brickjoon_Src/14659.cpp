#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int N, b{}, t{}, D{},F{};
	cin >> N;
	while(N--) 
	{
		cin >> t;
		if (b < t)
		{
			swap(b, t);
			if (F < D) swap(F, D);
			D = 0;
		}
		else D++;
	}
	cout << (D > F ? D : F);
}

// solve