#pragma warning(disable:4996)
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	double a,b;
	cin >> a >> b;
	a = powf(a, b);
	cout << a << "\n";
}

/*
#include <iostream>
#include <string>

using namespace std;

void spilt1(string a)
{
	cout << str.find(a) << "\n";
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		auto* str1 = new string;
		cin >> str1;
		spilt1(str1)
		delete str1;
	}
}
*/