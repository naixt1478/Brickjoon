#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	lli N, K, sum, max1{}, t{}, t2{};
	cin >> N >> K;
	deque<lli> num(N);
	for (auto& n : num) cin >> n;
	for (lli i = 0; i < N; i++)
	{
		sum = 0;
		for(int i = 0; i < K; i++)
		{
			sum += num.front();
			num.emplace_back(num.front());
			num.pop_front();
			t++;
		}
		max1 = max(max1, sum);
	}
	cout << max1;
}
/*
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int N, K, t{},sum{};
	cin >> N >> K;
	priority_queue<int> pq1;
	while(N--)
	{
		cin >> t;
		pq1.push(t);
	}
	while(K--)
	{
		sum += pq1.top();
		pq1.pop();
	}
	cout << sum;
}
*/