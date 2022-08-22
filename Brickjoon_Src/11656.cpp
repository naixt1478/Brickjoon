#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
typedef basic_string<char> bsc;

int main()
{
	_FASTIOS;
	bsc S;
	priority_queue<bsc, vector<bsc>, rng::greater> pq1;
	cin >> S;
	int Slen = S.length();
	for(int i = 0; i < Slen; i++) pq1.push(S.substr(i));
	while (!pq1.empty())
	{
		cout << pq1.top() << '\n';
		pq1.pop();
	}
}

// solve