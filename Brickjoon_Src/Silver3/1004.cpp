#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
typedef long long int lli;

struct xyr
{
	int x, y, r;
};

int main()
{
	_FASTIOS;
	int T,x1,x2,y1,y2,n;
	cin >> T;
	while(T--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		vector<xyr> route1(n);
		for(auto& [x,y,r] : route1) cin >> x >> y >> r;

	}
}