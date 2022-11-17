#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	vector<char> check = { 'U','C','P','C' };
	int N{};
	string s1;
	getline(cin, s1);
	for(auto& c : s1)
	{
		if(c == check[N])
		{
			if (++N == 4) break;
		}
	}
	if (N == 4) cout << "I love UCPC";
	else cout << "I hate UCPC";
}

// solve