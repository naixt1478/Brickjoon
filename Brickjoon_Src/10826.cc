#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

vector<string> memo(10001, "");

basic_string<char> fact1(int n)
{
    if(n <= 2 || memo[n] != "")
    {
        return memo[n];
    }
    basic_string<char> str = fact1(n-2),str2 = fact1(n-1);
    int s1l = str.length(), s2l = str2.length();
    vector <int> s1(int(max(s1l, s2l) + 1));
    for (int i = 0; i < s1.size()-1; i++)
    {
        auto maxs1 = (0 + i);
        if (s1l - i > 0) s1[maxs1] += int(str[s1l - i-1] - '0');
        if (s2l - i > 0) s1[maxs1] += int(str2[s2l - i-1] - '0');
        if (s1[maxs1] >= 10)
        {
            s1[maxs1] %= 10;
            s1[maxs1 + 1]++;
        }
    }
	for (int i = s1.size() - 1; i >= 0; i--)
	{
		if (s1.size() - 1 == i and s1[i] == 0) continue;
		memo[n].push_back(s1[i]+'0');
	}
	return memo[n];
}

int main()
{
    __fastios;
    memo[0] = "0";
    memo[1] = "1";
    memo[2] = "1";
    int n;
    cin >> n;
    cout << fact1(n);
}

// solve