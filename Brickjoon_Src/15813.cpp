#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(0);
	int sum{},l;
	string S;
	cin >> l >> S;
	for(auto& c : S) sum += c - 64;
	cout << sum;
}

// solve