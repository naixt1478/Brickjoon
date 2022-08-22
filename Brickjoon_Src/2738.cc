#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
    __fastios;
    int n,m,a;
    cin >> n >> m;
    vector<vector<int>> vvi1(n,vector<int>(m));
    for(auto& vi1 : vvi1)
    for(auto& i1 : vi1) cin >> i1;
    for(auto vi1 : vvi1)
    {
        for(auto i1 : vi1) 
        {
            cin >> a;
            cout << i1 + a << ' ';
        }
        cout << '\n';
    }
}

// solve