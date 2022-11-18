#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define ts to_string
using namespace std;

int main()
{
    bool _t1{0};
    pair<int,int> pii1 = {0,0};
    __fastios;
    basic_string<char> bsc1;
    cin >> bsc1;
    for(auto& c1 : bsc1)
    {
        if(c1 == '@') 
        {
            if(_t1) pii1.second++;
            else pii1.first++;
        }
        else if (c1 == '(') _t1 = 1;
    }
    cout << ts(pii1.first) + " " + ts(pii1.second);
}

// solve