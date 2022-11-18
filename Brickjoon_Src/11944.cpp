#include <bits/stdc++.h>
using namespace std;

int main()
{
	basic_string<char> bsc1;
	int N,M;
	cin >> N >> M;
	bsc1 = to_string(N);
	for (int i = 0; i < M && i < bsc1.length()*N; i++)
	{
		cout << bsc1[i % bsc1.length()];
	}
}

// solve