#include "bits/stdc++.h"
using namespace std;

int main()
{
    basic_string<char> bsc,bsc2;
    cin >> bsc;
    istringstream iss1(bsc);
    int sum1{};
    while(getline(iss1,bsc2,',')) sum1 += stoi(bsc2);
    cout << sum1;
}

// solve