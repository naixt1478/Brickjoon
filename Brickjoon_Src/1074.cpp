#include "bits/stdc++.h"
using namespace std;


int solve(int a,int b,int x,int y)
{
	int i1 = static_cast<int>(powf(2, a)) / 2;
	int i2 = static_cast<int>(powf(i1, 2));
	if(a == 0)
	{
		return b;
	}
	else
	{
		if(x < i1 && y < i1)
		{
			return solve(a - 1, b, x, y);
		}
		else if(x >= i1 && y < i1)
		{
			return solve(a - 1, b + i2 * 1, x - i1, y);
		}
		else if(x < i1 && y >= i1)
		{
			return solve(a - 1, b + i2 * 2, x, y - i1);
		}
		else if(x >= i1 && y >= i1)
		{
			return solve(a - 1, b + i2 * 3, x - i1, y - i1);
		}
	}
}

int main()
{
	int N, r, c;
	cin >> N >> r >> c;
	cout << solve(N,0,c,r);
}

// solve