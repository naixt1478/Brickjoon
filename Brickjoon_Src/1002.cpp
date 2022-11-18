#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(0);
	int n,x1,x2,y1,y2,sub,add;
	double dis;
	vector<int> r(2);
	cin >> n;
	while (n--)
	{
		cin >> x1 >> y1 >> r[0] >> x2 >> y2 >> r[1];
		dis = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
		ranges::sort(r);
		sub = r[1] - r[0];
		add = r[1] + r[0];
		if (dis == 0 && sub == 0) cout << -1;
		else if(sub < dis && dis < add) cout << 2;
		else if(sub == dis || add == dis) cout << 1;
		else cout << 0;
		cout << '\n';
	}
}

// solve