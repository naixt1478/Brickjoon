#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	basic_string<char> bsc1;
	cin >> n;
	for(int i = 0; i <= n; i++)
	{
		if(i==0)
		{
			cout << "int a;\n";
			bsc1 = "a";
		}
		else
		{
			cout << "int " + basic_string<char>(i, '*') + "ptr" + (i == 1 ? "" : to_string(i)) + " = &" + bsc1 + ";" << '\n';
			bsc1 = "ptr" + (i == 1 ? "" : to_string(i));
		}
	}
}

// solve