#include <bits/stdc++.h>
using namespace std;

void clear(queue<pair<int,int>>& q1)
{
	queue<pair<int, int>> q2;
	q1.swap(q2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int T, N, M, temp, cnt;
	vector<int> v1;
	queue<pair<int,int>> q1;
	cin >> T;
	while(T--)
	{
		cnt = 0;
		v1.clear();
		clear(q1);
		cin >> N >> M;
		for(int i = 0; i < N; i++)
		{
			cin >> temp;
			q1.push(pair(i, temp));
			v1.emplace_back(temp);
		}
		ranges::sort(v1, greater<int>());
		while(!q1.empty())
		{
			auto& [a,b] = q1.front();
			q1.pop();
			if(b != v1[cnt])
			{
				q1.push(pair(a, b));
			}
			else
			{
				cnt++;
				if (a == M) break;
			}
		}
		cout << cnt << '\n';
	}
}

// solve