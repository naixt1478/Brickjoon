#include <iostream>

using namespace  std;

int r(int a)
{
	int b = a/100;
	int c = a%100-a%10;
	int d = a%10*100;
	return (b+c+d);
}

int main()
{
	ios_base::sync_with_stdio(0);
	int a,b;
	cin >> a >> b;
	a = r(a);
	b = r(b);
	if(a > b)
		cout << a;
	else
		cout << b;
}

// solve