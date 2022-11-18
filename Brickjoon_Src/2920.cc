#include <iostream>

using namespace std;

int main()
{
	int n, a = 0;
	for(int i = 0; i < 8; i++)
	{
		cin >> n;
		if(n == i+1)
			a += 1;
		else if (n == 8-i)
			a += -1;
		else
			a = 0;
	}
	if(a == 8)
		cout << "ascending";
	else if (a == -8)
		cout << "descending";
	else
		cout << "mixed";
}

// solve