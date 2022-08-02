#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template <typename T>
using V = vector<T>;

struct _2i
{
	int num = 0, cnt = 0;
};

int main()
{
	__fastios;
	_2i min1, max1;
	int bal1{}, t;
	size_t n{};
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> t;
		if (i != 0 && max1.num <= t) max1 = { t,max1.cnt + 1 };
		else
		{
			bal1 = rng::max(max1.cnt, bal1);
			max1 = { t,1 };
		}
		if (i != 0 && min1.num >= t) min1 = { t,min1.cnt + 1 };
		else
		{
			bal1 = rng::max(min1.cnt, bal1);
			min1 = { t,1 };
		}
	}
	bal1 = rng::max({ min1.cnt,max1.cnt,bal1 });
	cout << bal1;
}

// solve