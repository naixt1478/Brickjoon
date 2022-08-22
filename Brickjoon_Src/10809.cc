#include <iostream>
#include <string>

using namespace  std;

int main()
{
	string s;
	cin >> s;
	int a = 0;
	for(int i = 97; i < 123; i++)
	{
		a = 0;
		if(s.find(i, 0) > s.size())
			a = -1;
		else
			 a = s.find(i, 0);
		cout << a << " ";
	}
}

// solve