#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int x,y;
	cin >> x >> y;
	if(x > 0)
	{
		if (y > 0)
			cout << 1;
		else
			cout << 4;
	}
	else
	{
		if (y > 0)
			cout << 2;
		else
			cout << 3;
	}
}

// solve