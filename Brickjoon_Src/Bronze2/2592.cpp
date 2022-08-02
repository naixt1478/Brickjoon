#include <bits/stdc++.h>
using namespace std;

int main()
{
	int sum{}, m1{}, m2{}, temp{};
	vector<int> vi1(101);
	for (int i = 0; i < 10; i++)
	{
		cin >> temp;
		vi1[temp / 10]++;
		sum += temp;
		if (vi1[temp / 10] > m2)
		{
			m1 = temp;
			m2 = vi1[temp/10];
		}
	}
	cout << sum / 10 << '\n' << m1;
}

// solve
