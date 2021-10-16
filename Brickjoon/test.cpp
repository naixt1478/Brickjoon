#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, a;
	cin >> n >> m;
	vector<long long> num1;
	for (int i = 0; i < n; i++)
	{
		num1.clear();
		for (int j = 0; j < m; j++)
		{
			cin >> a;
			num1.push_back(a);
		}
		sort(num1.begin(), num1.end(), greater<long long>());
		for (int j = 0; j < m; j++)
		{
			if(j == m-1)
			{
				cout << num1[j];
			}
			else
			{
				cout << num1[j] << " ";
			}
		}
		if(i == n-1)
		{
		 break;
		}
		else
		{
		cout << '\n';
		}
	}
	return 0;
}