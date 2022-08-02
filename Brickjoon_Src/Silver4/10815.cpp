#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
	_FASTIOS;
	int N, M;
	cin >> N;
	vector<int> vi1(N);
	for(auto& i1 : vi1) cin >> i1;
	rng::sort(vi1);
	cin >> M;
	while(M--)
	{
		cin >> N;
		cout << rng::binary_search(vi1, N) << ' ';
	}
}

// solve