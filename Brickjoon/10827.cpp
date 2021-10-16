#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	double a, b;
	cin >> a >> b;
	a = powf(a, b);
	cout << a << "\n";
}

// solving in progress