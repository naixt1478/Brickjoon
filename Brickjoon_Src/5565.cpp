#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
    _FASTIOS;
    int max1{},sum1{},s,t{9};
    cin >> max1;
    while(t--) 
    {
        cin >> s;
        sum1 += s;
    }
    cout << max1 - sum1;
}

// solve