#include <bits/stdc++.h>
using namespace std;
namespace rng = ranges;

int main()
{
	int n;
	cin >> n;
	vector<int> vi1(3);
	for(int i = 1; i <= n; i++)
	{
		cout << "Scenario #" << i << ":\n";
		for (auto& i : vi1) cin >> i;
		rng::sort(vi1);
		if((vi1[0] * vi1[0] + vi1[1] * vi1[1]) == (vi1[2] * vi1[2]))
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
		if(i!=n) cout << '\n';
	}
}

// solve
