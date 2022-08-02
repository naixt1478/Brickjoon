#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;
namespace rng = ranges;

int main()
{
	_FASTIOS
	int N,T;
	cin >> T;
	priority_queue<int, vector<int>, greater<>> minq1;
	priority_queue<int, vector<int>, less<>> maxq1;
	for(int i = 1; i <= T; i++)
	{
		cin >> N;
		if (maxq1.empty()) maxq1.push(N);
		else if (minq1.empty() ^ 1 && N < minq1.top()) maxq1.push(N);
		else maxq1.push(N);
		while (maxq1.size() > minq1.size())
		{
			minq1.push(maxq1.top());
			maxq1.pop();
		}
		while (maxq1.size() < minq1.size())
		{
			maxq1.push(minq1.top());
			minq1.pop();
		}
		if(i%2) cout << maxq1.top() << '\n';
		else cout << rng::min(maxq1.top(), minq1.top()) << '\n';
	}
}

// solve