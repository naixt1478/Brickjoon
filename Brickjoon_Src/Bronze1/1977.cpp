#include <bits/stdc++.h>
using namespace std;

int main()
{
	int M, N, sum1{}, min1{0};
	cin >> M >> N;
	for (int i = M; i <= N; i++)
	{
		if (ceil(sqrt(i)) == floor(sqrt(i)))
		{
			sum1 += i;
			if (min1 == 0) min1 = i;
		}
	}
	if (sum1 == 0) cout << -1;
	else cout << sum1 << '\n' << min1;
}

// solve