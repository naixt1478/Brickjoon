#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr)
using namespace std;

int main()
{
    __fastios;
    basic_string <char> bsc;
    int T;
	unsigned int x,i1 = 0,f;
    cin >> T;
    while(T--)
    {
    	f = 1;
        cin >> bsc;
        if (bsc == "add")
        {
            cin >> x;
            f <<= x-1;
            i1 |= f;
        }
        else if (bsc == "remove")
        {
            cin >> x;
            f <<= x-1;
            if(i1 > (i1 ^ f)) i1 ^= f;
        }
        else if (bsc == "check")
        {
            cin >> x;
            f <<= x - 1;
            if ((i1 ^ f) > i1) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else if (bsc == "toggle")
        {
            cin >> x;
            f <<= x - 1;
            i1 ^= f;
        }
        else if (bsc == "all")
        {
            i1 = (1 << 20) - 1;
        }
        else i1 = 0;
    }
}
