#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int mode{0}, n, max, p{0},i{0};
	double sum{},n1;
	cin >> n;
	vector<int> t(n),count(8001);
	for(auto& num : t)
	{
		cin >> num;
		sum += num;
		count[num+4000]++;
	}
	max = *ranges::max_element(count);
	while(i != 8001)
	{
		if (p == 2) break;
		else if (count[i] == max)
		{
			p++;
			mode = i-4000;
		}
		i++;
	}
	n1 = n;
	ranges::sort(t);
	cout << lround(sum/n1) << '\n'; // fixed -0 -> 0 to round to lround
	cout << t[n / 2] << '\n';
	cout << mode << '\n';
	cout << t[n-1] - t[0];
}

// solve