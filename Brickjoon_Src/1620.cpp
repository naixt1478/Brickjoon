#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
	__fastios;
	unordered_map<string, int> map1;
	vector<string> vs1 = {""};
	int N, M;
	basic_string<char> bsc = {0};
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
	{
		cin >> bsc;
		map1.insert(pair(bsc, i));
		vs1.emplace_back(bsc);
	}
	for(int i = 0; i < M; i++)
	{
		cin >> bsc;
		if(bsc[0] > 64)
		{
			cout << map1[bsc] << '\n';
		}
		else
		{
			cout << vs1[stoi(bsc)] << '\n';
		}
	}
}

// solve