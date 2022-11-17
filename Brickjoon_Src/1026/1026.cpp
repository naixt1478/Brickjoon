#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int sum{}, N;
	cin >> N;
	vector<int> a(N), b(N);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
	ranges::sort(a);
	ranges::sort(b, greater<>());
	for (int i = 0; i < N; i++) sum += a[i] * b[i];
	cout << sum;
}

// solve