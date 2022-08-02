#include <bits/stdc++.h>
using namespace std;

int main()
{
	unsigned long long int num1, num2;
	basic_string <char> a, b, c, d;
	cin >> a >> b >> c >> d;
	a += b;
	c += d;
	stringstream ss1(a);
	ss1 >> num1;
	stringstream ss2(c);
	ss2 >> num2;
	cout << num1 + num2;
}

// solve