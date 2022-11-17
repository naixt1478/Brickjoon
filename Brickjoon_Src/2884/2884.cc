#include <iostream>

using namespace  std;

int main()
{
	int h, m;
	cin >> h >> m;
	int t = m-45;
		if(h == 0 && t < 0)
		{
			h = 23;
			m = 60+t;
		}
		else if (t < 0)
		{
			h--;
			m = 60+t;
		}
		else
			m = t;
	cout << h << " " << m;
}

// solve