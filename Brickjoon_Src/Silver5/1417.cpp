#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int t,n{};
	cin >> t;
	vector<int> vote(t+1);
	for (int i = 0; i < t; i++) cin >> vote[i];
	while(vote[0] <= *ranges::max_element(vote.begin() + 1, vote.end()))
	{
		*ranges::max_element(vote.begin() + 1, vote.end())-=1;
		vote[0]++;
		n++;
	}
	cout << n;
}

// solve