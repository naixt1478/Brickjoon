#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	int n, b, c;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	b = a[0],c = a[0];
	for(int i = 0; i < n; i++)
	{
		if(a[i] < b)
			b = a[i];
		if(a[i] > c)
			c = a[i];
	}
	cout << b << " " << c;
}

// solve