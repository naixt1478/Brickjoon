#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
    __fastios;
    int n,k,i{0},i2{0};
    cin >> n >> k;
    while(i<k)
    {
        i2++;
        if(n%i2 == 0) i++;
        else if(n<i2)
        {
            i2 = 0;
            break;
        }
    }
    cout << i2;
}

// solve