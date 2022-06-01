#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int f{}, t{};
	char a{};
	string s1;
	cin >> s1;
	for(auto& c : s1)
	{
		if(a!=c)
		{
			if(c=='1') t++;
			else f++;
		}
		a=c;
	}
	cout << min(t, f);
}

// solve
