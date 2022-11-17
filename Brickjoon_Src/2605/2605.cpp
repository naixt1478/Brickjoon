#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	int n,t;
	_FASTIOS;
	cin >> n;
	vector<int> vi1;
	for(int i = 1; i <= n; i++)
	{
		cin >> t;
		vi1.insert(vi1.end()-t, i);
	}
	for (auto& i1 : vi1) cout << i1 << ' ';
}

// solve