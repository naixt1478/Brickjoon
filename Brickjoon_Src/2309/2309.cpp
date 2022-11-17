#include <bits/stdc++.h>
using namespace std;
namespace rng = ranges;

int main()
{
	int sum{};
	vector<int> vi1(9);
	for (auto& i1 : vi1)
	{
		cin >> i1;
		sum += i1;
	}
	rng::sort(vi1);
	for (int i = 0; i < 9; i++)
	for (int j = 0; j < 9; j++)
	{
		if (i == j) continue;
		else if(sum - vi1[i] - vi1[j] == 100)
		{
			vi1[i] = false;
			vi1[j] = false;
			i = INT_MAX - 1;
			break;
		}
	}
	for(auto& i1 : vi1)	if (i1 ^ 0) cout << i1 << '\n';
	return 0;
}

// solve