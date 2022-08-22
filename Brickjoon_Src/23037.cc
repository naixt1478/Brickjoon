#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
    __fastios;
    int n;
    cin >> n;
    int sum1{};
    while(n!=0)
    {

        sum1 += static_cast<int>(pow(n%10, 5));
        n /= 10;
    }
    cout << sum1;
}

// solve