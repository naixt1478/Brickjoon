#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a = 0;
	vector<int> vi1(9);
	for(auto& i1 : vi1)
	{
		cin >> i1;
		a += i1;
	}
	for (int i = 0; i < 9; i++)
	{
		for(int j = i+1; j < 9; j++)
		{
			if(a - vi1[i] - vi1[j] == 100)
			{
				for(int k = 0; k < 9; k++)
				{
					if(k != i && k != j)
					{
						cout << vi1[k] << '\n';
					}
				}
			}
		}
	}
}

// solve