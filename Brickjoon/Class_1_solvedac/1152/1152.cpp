#include <iostream>
#include <string>

using namespace  std;

int main()
{
	string n;
	getline(cin, n);
	int a = n.size(), b = 1;

	for (int i = 0; i < a; i++)
	{
		if (n[i] == ' ')
			b++;
	}
	if (n[0] == ' ')
		b--;
	if(n[a-1] == ' ')
		b--;
	cout << b;
}

//solved