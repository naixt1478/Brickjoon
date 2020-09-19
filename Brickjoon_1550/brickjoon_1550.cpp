#include <iostream>

using namespace std;

int main()
{
	char n[100];
	cin >> n;
	cout << static_cast<int>(strtol(n, nullptr, 16));
}

// solved