#include <iostream>

using namespace std;

int main()
{
	int t,r = 0;
	cin >> t;
	string str;
	while(t--)
	{
		cin >> r >> str;
		for(int i = 0; i < str.length(); i++)
		{
			for(int j = 0; j < r; j++)
				cout << str.at(i);
		}
		cout << "\n";
	}
}

// solve