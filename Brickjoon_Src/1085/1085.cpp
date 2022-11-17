#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int x, y, w, h, a, b;
	cin >> x >> y >> w >> h;
	w -= x, h -= y;
	a = x > w ? w : x;
	b = y > h ? h : y;
	cout << (a > b ? b : a);
}

// solve