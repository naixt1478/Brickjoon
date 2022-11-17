#include "bits/stdc++.h"
using namespace std;

int main()
{
    basic_string<char> bsc1;
    while(getline(cin,bsc1))
    {
        if(bsc1 == "END") break;
        for(int i = bsc1.length()-1; i >= 0; i--)
        {
            cout << bsc1[i];
        }
        cout << '\n';
    }
}

// solve