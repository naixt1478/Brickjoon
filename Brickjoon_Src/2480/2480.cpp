#include <iostream>

using namespace std;

int main()
{
	int a[5], i = 3, t(0),max(0);
	while (i--)
	{
		cin >> a[i];
		if (max < a[i])
			max = a[i];
	}
	if (a[2] == a[0])
	{
		t++;
		max = a[2];
	}
	if (a[2] == a[1])
	{
		t++;
		max = a[2];
	}
	if (a[0] == a[1])
	{
		t++;
		max = a[0];
	}
	if (t >= 2)
		cout << 10000 + a[2] * 1000;
	else if (t == 1)
		cout << 1000 + max * 100;
	else
		cout << max * 100;
}

// solved