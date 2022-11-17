#include <bits/stdc++.h>
using namespace std;
namespace rng = ranges;

int main()
{
	int a, b, c, max1;
	while (cin >> a >> b >> c, a != 0, b != 0, c != 0)
	{
		max1 = rng::max({ a,b,c });
		if (max1 >= (a+b+c-max1))
		{
			cout << "Invalid\n";
		}
		else if(a == b && b == c)
		{
			cout << "Equilateral\n";
		}
		else if(a == b || b == c || c == a)
		{
			cout << "Isosceles\n";
		}
		else
		{
			cout << "Scalene\n";
		}
	}
}

// solve