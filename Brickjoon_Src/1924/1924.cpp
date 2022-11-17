#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	vector<string> d = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	int x, y, sum = 0;
	cin >> x >> y;
	for(int i = 1; i < x; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) sum += 31;
		else if (i == 2) sum += 28;
		else sum += 30;
	}
	cout << d[(sum + y-1) % 7];
}

// solve