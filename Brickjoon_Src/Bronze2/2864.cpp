#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int max{}, min{}, t;
	string s1;
	stringstream ss1, ss2;
	getline(cin, s1);
	ss1.str(regex_replace(s1, regex("6"), "5"));
	ss1 >> min >> t;
	min += t;
	ss2.str(regex_replace(s1, regex("5"), "6"));
	ss2 >> max >> t;
	max += t;
	cout << min << ' ' << max;
}

// solve