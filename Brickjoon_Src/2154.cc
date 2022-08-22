#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    basic_string<char> bsc;
    for(int i = 1; i <= n; i++)
    {
        bsc += to_string(i);
    }
    cout << bsc.find(to_string(n)) + 1;
}

// solve