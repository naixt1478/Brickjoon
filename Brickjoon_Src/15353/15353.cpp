#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	vector<int> a, b;
	for (int i = str1.length(); 0 <= i; i--)
	{
		a.push_back(str1.at(i) - '0');
	}
	for (int i = 0; i < str1.length(); i++)
	{
		cout << a[i] << ' ';
	}
}

// solve