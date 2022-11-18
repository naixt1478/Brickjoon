#include <bits/stdc++.h>
using namespace std;
namespace rng = ranges;

void s1(int a)
{
	vector<int> vi1(a);
	for(int& i1 : vi1) cin >> i1;
	rng::sort(vi1);
	int c = vi1[0], b = 0;
	for(int i1 : vi1)
	{
		if(i1 - c > b) b = i1 - c;
		c = i1;
	}
	cout << "Max " << *prev(vi1.end()) << ", Min " << *vi1.begin() << ", Largest gap " << b << '\n';
}

int main()
{
	int k, n;
	cin >> k;
	for(int i = 1; i <= k; i++)
	{
		cin >> n;
		cout << "Class " << i << '\n';
		s1(n);
	}
}

// solve