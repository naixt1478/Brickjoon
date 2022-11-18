#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
    int a{};
    vector<char> ch = {'a','e','i','o','u','A','E','I','O','U'};
    __fastios;
    basic_string<char> bsc1;
    while(getline(cin,bsc1),bsc1 != "#")
    {
        a = 0;
        for(auto& c1 : bsc1)
        {
            for(auto& c2 : ch)
            {
                if(c1 == c2)
                {
                    a++;
                }
            }
        }
        cout << a << '\n';
    }
}

// solve