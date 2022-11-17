#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int N, T{}, Y{}, M{};
	cin >> N;
	while(N--)
	{
		cin >> T;
		T++;
		Y += (T / 30 + 1) * 10;
		M += (T / 60 + 1) * 15;
	}
	if (Y < M) cout << "Y " << Y;
	else if (Y > M) cout << "M " << M;
	else cout << "Y M " << M;
}

// solve