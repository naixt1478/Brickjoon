#include <iostream>
#include <set>

using namespace  std;

int main()
{
	ios_base::sync_with_stdio(0);
	int temp;
	set<int> a;
	for(int i = 0; i < 10; i++)
	{
		cin >> temp;
		a.insert(temp%42);
	}
	cout<< a.size();
}

// solve