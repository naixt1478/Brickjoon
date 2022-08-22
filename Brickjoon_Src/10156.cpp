#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
	if (a * b - c < 0)
		cout << 0;
	else
		cout << a * b-c;
}

// solve