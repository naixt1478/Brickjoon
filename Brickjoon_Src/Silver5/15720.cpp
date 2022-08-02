#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int B, C, D, temp{}, cnt{}, sum{}, sum2{}, max1{};
	cin >> B >> C >> D;
	max1 = max({ B,C,D });
	vector<vi> vv1(3, vi(max1, 0));
	while (B--) cin >> vv1[0][B];
	while (C--) cin >> vv1[1][C];
	while (D--) cin >> vv1[2][D];
	for (auto& v1 : vv1) ranges::sort(v1, greater<>());
	for (int i = 0; i < max1; i++)
	{
		cnt = 0,temp = 0;
		for(auto& v1 : vv1)
		{
			temp += v1[i];
			if (v1[i] != 0) cnt++;
		}
		sum += temp;
		if(cnt==3) sum2 += temp * 0.9;
		else sum2 += temp;
	}
	cout << sum << "\n" << sum2;
}

// solve