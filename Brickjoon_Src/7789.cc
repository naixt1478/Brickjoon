#include "bits/stdc++.h"
using namespace std;

int main()
{
	basic_string<char> bsc1, bsc2;
	cin >> bsc1 >> bsc2;
	bool b1 = 0;
	int a = stoi(bsc1), b = stoi(bsc2 + bsc1);
	for(int i = 2; i < a || i < b; i++)
	{
		if(i < a && a%i == 0)
		{
			b1 = 1;
			break;
		}
		else if(i < b && b%i == 0)
		{
			b1 = 1;
			break;
		}
	}
	if (b1) cout << "No";
	else cout << "Yes";
}

// solve