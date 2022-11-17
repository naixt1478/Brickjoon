#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long a, b, t{1};
	string str;
	cin >> a >> a >> b;
	cin.ignore();
	getline(cin, str);
	while(b--) t = t * a % 26;
	for(char const c1 : str)
	{
		if(c1 == ' ') cout << c1;
		else
		{
			cout << static_cast<char>((c1 + 'A' + 26 - t) % 26 + 'A');
		}
	}
	cout << '\n';
}

// solve