#include <bits/stdc++.h>
using namespace std;

struct cake_num
{
	int x, y, z;
};

int main()
{
	cake_num a,c;
	cin >> a.x >> a.y >> a.z;
	cin >> c.x >> c.y >> c.z;
	cout << c.x - a.z << ' ' << c.y / a.y << ' ' << c.z - a.x;
}

// solve