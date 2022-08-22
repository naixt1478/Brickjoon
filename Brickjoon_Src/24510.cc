#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
    __fastios;
    int T, i1{ 0 }, i2{ 0 }, pos{ 0 };
    basic_string<char> bsc;
    cin >> T;
    while (T--)
    {
        cin >> bsc;
        pos = 0;
        i2 = 0;
        while (1)
        {
            auto r1 = bsc.find("for", pos), r2 = bsc.find("while", pos);
            if (r1 == string::npos && r2 == string::npos) break;
            else
            {
                if (r1 > r2)
                {
                    pos = r2 + 5;
                    i2++;
                }
                else
                {
                    pos = r1 + 3;
                    i2++;
                }
            }
        }
        if (i2 > i1) i1 = i2;
    }
    cout << i1;
}

// solve