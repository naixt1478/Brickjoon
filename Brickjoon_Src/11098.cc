#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
    __fastios;
    int T,T2;
    cin >> T;
    while(T--)
    {
        int max1 = -1,temp;
        basic_string<char> bsc1 = "",bsc2;
        cin >> T2;
        while(T2--)
        {
            cin >> temp >> bsc2;
            if(temp > max1) 
            {
                max1 = temp;
                bsc1 = bsc2;
            }
        }
        cout << bsc1 << '\n';
    }
}

// solve