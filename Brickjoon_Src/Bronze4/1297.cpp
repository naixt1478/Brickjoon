#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int D, H, W;
	double pos;
	cin >> D >> H >> W;
	pos = sqrt(H * H + W * W);
	cout << floor(D * H / pos) << ' ' << floor(D * W / pos);
}

// solve