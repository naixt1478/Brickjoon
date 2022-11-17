#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
constexpr int mod = 10007;

int main()
{
    _FASTIOS;
    int n;
    cin >> n;
    vector<int> vi1 = {1,1};
    for(int i = 2; i <= n; i++)
    {
        if(i % 2 == 0) vi1.emplace_back((vi1[i - 1]%mod * 2 + 1) % mod);
        else vi1.emplace_back((vi1[i - 1] % mod * 2 - 1) % mod);
    }
    cout << vi1[n];
}

// solve