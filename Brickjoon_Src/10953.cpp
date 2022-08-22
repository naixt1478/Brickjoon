#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	int n,a(0);
	cin >> n;
	string str1, str2;
	for (int i = 0; i < n; i++)
	{
		a = 0;
		cin >> str1;
		stringstream ss1(str1);
		while (getline(ss1, str2, ','))
			a += stoi(str2);
		cout << a << '\n';
	}
}

// solve