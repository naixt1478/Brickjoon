#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int N;
	cin >> N;
	cout << (1 + N / 2) * (1 + N / 2 + N % 2);
}

// solve