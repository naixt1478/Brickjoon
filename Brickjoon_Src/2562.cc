#include <iostream>

using namespace std;

int main()
{
	int n,a,b;
	ios_base::sync_with_stdio(0);
	for(int i = 0; i < 9; i++)
	{
		cin >> n;
		if(i == 0)
			a = n,b = 1;
		else if (n > a)
		{
			a = n;
			b = i+1;
		}
	}
	cout << a << "\n" << b;
}

// solve