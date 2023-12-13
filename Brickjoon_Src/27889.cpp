#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
    __fastios;
    basic_string<char> bsc1;
    cin >> bsc1;
    if(bsc1 == "NLCS") cout << "North London Collegiate School";
    if(bsc1 == "BHA") cout << "Branksome Hall Asia";
    if(bsc1 == "KIS") cout << "Korea International School";
    if(bsc1 == "SJA") cout << "St. Johnsbury Academy";
    return 0;
}

// solve