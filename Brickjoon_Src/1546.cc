#include <iostream>

using namespace  std;

int main()
{
	ios_base::sync_with_stdio(0);
	int n, a;
	double m = 0.0,b = 0.0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		if(a > m)
			m = a;
		b += a;
	}
	cout << b/m*100/double(n);
}

// solve