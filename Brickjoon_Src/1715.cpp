#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,temp{}, sum{}, sum2{}, sum3{};
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq1;
	while(N--)
	{
		cin >> temp;
		pq1.push(temp);
	}
	while(pq1.size() > 1)
	{
		sum = pq1.top();
		pq1.pop();
		sum2 = pq1.top();
		pq1.pop();
		pq1.push(sum + sum2);
		sum3 += sum2 + sum;
	}
	cout << sum3;
}

// solve
// soon retry not using STL