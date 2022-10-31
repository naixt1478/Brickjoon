#include <iostream>

using namespace std;

int main()
{
	int n, a=0;
	cin >> n;
	string str;
	cin >> str;
	for(int i = 0; i < n; i++)
	{
		a += (str.at(i)) - '0';
	}
	cout << a;
}

// solve