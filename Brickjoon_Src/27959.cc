#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
    __fastios;
    int N,M;
    cin >> N >> M;
    if(N*100 >= M) cout << "Yes";
    else cout << "No";
}

// solve