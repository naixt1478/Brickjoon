#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int s1()
{
    int W{},B{};
    size_t n;
    basic_string<char> bsc1,bsc2;
    cin >> n >> bsc1 >> bsc2;
    for(size_t i = 0; i < n; i++)
    {
        if(bsc1[i] != bsc2[i])
        {
            if(bsc1[i] == 'W') W++;
            else B++;
        }
    }
    return max(W,B);
}

int main()
{
    __fastios;
    int T;
    cin >> T;
    while(T--) cout << s1() << '\n';
}

// solve