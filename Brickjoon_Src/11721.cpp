#include <iostream>

using namespace std;

int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		cout << str.at(i);
		if ((i + 1)%10 == 0)
		{
			cout << '\n';
		}
	}
}

// solve