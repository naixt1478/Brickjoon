#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
    __fastios;
    long long int n,i1=1;
    cin >> n;
    for(int i = 1; i <= n; i++)
        i1*=i;
    if(n==0) n = 1;
    cout << i1;
}

// solve