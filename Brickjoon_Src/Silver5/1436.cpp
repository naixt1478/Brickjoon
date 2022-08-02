#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, t{665}, c{};
	string s;
	cin >> n;
	while(n!=c)
	{
		t++;
		if(to_string(t).find("666") != string::npos) c++;
	}
	cout << t;
}

// solve