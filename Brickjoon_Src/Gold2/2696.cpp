#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;
namespace rng = ranges;

void solve()
{
	int T,F;
	cin >> T;
	priority_queue<int, vector<int>, greater<>> minq1;
	priority_queue<int, vector<int>, less<>> maxq1;
	cout << (T + 1) / 2 << '\n';
	for(int i = 1; i <= T; i++)
	{
		cin >> F;
		if (maxq1.empty()) maxq1.push(F);
		else if (minq1.empty() ^ 1 && F < minq1.top()) maxq1.push(F);
		else maxq1.push(F);
		while(maxq1.size() > minq1.size())
		{
			minq1.push(maxq1.top());
			maxq1.pop();
		}
		while(maxq1.size() < minq1.size())
		{
			maxq1.push(minq1.top());
			minq1.pop();
		}
		if(i % 2 != 0) cout << maxq1.top() << ' ';
	}
	cout << '\n';
}

int main()
{
	_FASTIOS
	int N;
	cin >> N;
	while(N--)
	{
		solve();
	}
}

// solve