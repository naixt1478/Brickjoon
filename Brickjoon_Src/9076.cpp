#include <bits/stdc++.h>
using namespace std;

void s1()
{
	vector<int> vi1(5);
	for(auto& i1 : vi1)
	{
		cin >> i1;
	}
	ranges::sort(vi1);
	vi1.erase(vi1.begin());
	vi1.erase(prev(vi1.end()));
	if (abs(vi1[0] - vi1[2]) >= 4) cout << "KIN\n";
	else cout << accumulate(vi1.begin(), vi1.end(), 0) << '\n';
}

int main()
{
	int t1;
	cin >> t1;
	while(t1--)
	{
		s1();
	}
}

// solve