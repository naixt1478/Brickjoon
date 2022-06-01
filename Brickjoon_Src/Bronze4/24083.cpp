#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	while(b--) 
	{
		a++;
		if (a == 13) a = 1;
	}
	cout << a;
}

// solve