#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, n{};
	cin >> n;
	a = (n / 10);
	b = (n % 10);
	while(true)
	{
		auto* temp = new int;
		*temp = (a + b);
		a = b;
		b = *temp%10;
		delete temp;
		if((a*10)+b == n)
		{
			c++;
			break;
		}
		c++;
	}
	cout << c;
}

// solve