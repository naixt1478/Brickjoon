#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, b = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> b;
		a[i] = b;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\n";
	}
}

// solve