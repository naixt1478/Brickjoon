#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n;
	double a, b;
	cin >> n;
	cout << fixed;
	cout.precision(18);
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cout << (a * b) << '\n';
	}
}