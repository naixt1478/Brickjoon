#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
const double PI = acos(-1);
typedef long long int lli;

int main()
{
	_FASTIOS;
	lli k, result{};
	double r, b{ -1 }, b2{ -1 }, x1, y1, r2{};
	cin >> k >> r2;
	if (k != 0 && r2 != 0)
	{
		r = r2 / k;
		for(int i = 1; i < 15000000; i++)
		{
			x1 = cosl(i * PI / 30000000) * r;
			y1 = sinl(i * PI / 30000000) * r;
			if (ceil(x1) != floor(x1) && ceil(y1) != floor(y1) && floor(b) != floor(x1) || floor(b2) != floor(y1))
			{
				result++;
				b = x1;
				b2 = y1;
			}
		}
	}
	cout << result*4;
}
