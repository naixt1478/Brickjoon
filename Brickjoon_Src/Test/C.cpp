#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	_FASTIOS;
	int T,N,cnt,cnt2;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cnt = 0;
		cin >> N;
		vector<int> vi1(N);
		for (auto& i1 : vi1) cin >> i1;
		sort(vi1.begin(), vi1.end(), greater<>());
		cnt2 = vi1[0];
		for (int j = 0; j < vi1.size(); j++)
		{
			if (vi1[0] == vi1[j]) cnt++;
			else
			{
				cnt--;
				break;
			}

			if (vi1.size() - 1 == j)
			{
				cnt--;
				break;
			}
		}
		cout << "Case #" << i << ": " << vi1.size() - cnt << '\n';
	}
}