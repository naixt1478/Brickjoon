#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	_FASTIOS;
	int temp,x,y,max{-1};
	for(int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> temp;
			if(temp > max)
			{
				x = i;
				y = j;
				max = temp;
			}
		}
	}
	cout << max << '\n' << x << ' ' << y;
}

// solve
