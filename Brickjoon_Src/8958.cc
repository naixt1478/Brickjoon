#include <iostream>

using namespace std;

int main()
{
	int n, a = 0, b = 0;
	string str;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> str;
		for(int j = 0; j < str.length(); j++)
		{
				if(str.at(j) == 'O')
				{
					a += 1 + b;
					b += 1;
				}
				else
					b = 0;
		}
		cout << a << "\n";
		a = 0,b = 0;
	}
}

// solve