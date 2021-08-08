#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	long a;
	int b, j;
	cin >> a;
	vector <long long> count1(10001);
	for (long i = 0; i < a; i++)
	{
		cin >> b;
		count1[b]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		j = count1[i];
		while (j--)
		{
			cout << i << "\n";
			count1[i]--;
		}
	}
}