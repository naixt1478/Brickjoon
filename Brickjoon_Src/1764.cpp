#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
using namespace std;
namespace rng = ranges;
typedef basic_string<char> bsc;

int main()
{
	_FASTIOS;
	int N, M;
	cin >> N >> M;
	vector<bsc> vbsc1(N);
	priority_queue<bsc, vector<bsc>, rng::greater> pq1;
	for (auto& bsc1 : vbsc1) cin >> bsc1;
	rng::sort(vbsc1);
	while(M--)
	{
		bsc bsc1;
		cin >> bsc1;
		if(rng::binary_search(vbsc1, bsc1)) pq1.push(bsc1);
	}
	cout << pq1.size() << '\n';
	while(!pq1.empty())
	{
		cout << pq1.top() << '\n';
		pq1.pop();
	}
}

// solve