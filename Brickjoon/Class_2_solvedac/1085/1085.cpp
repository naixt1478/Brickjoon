#include <iostream>

using namespace std;

int main()
{
	int x,y,w,h;
	cin >> x >> y >> w >> h;
	if ((w-x) > (h-y))
	{
		if (w+x == w+1)
			cout << 1;
		else if (h+y == h+1)
			cout << 1;
		else
			cout << (h-y);
	}
	else if ((w-x) < (h-y))
	{
		if (w+x == w+1)
			cout << 1;
		else if (h+y == h+1)
			cout << 1;
		else
			cout << (w-x);
	}
		
	else if ((w-x) == (h-y))
	{
		if (w+x == w+1)
			cout << 1;
		else if (h+y == h+1)
			cout << 1;
		else
			cout << (w-x);
	}
}

// solved 