#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    basic_string<char> bsc,bsc2;
    cin >> bsc;
    stack<char> sc1;
    for(auto& c1 : bsc)
    {
        while(k > 0 && !sc1.empty() && sc1.top() < c1)
        {
            bsc2.pop_back();
            sc1.pop();
            k--;
        }
        sc1.push(c1);
        bsc2.push_back(c1);
    }
    while(k>0) 
    {
        bsc2.pop_back();
        k--;
    }
    cout << bsc2;
}

// solve