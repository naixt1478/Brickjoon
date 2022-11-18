#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
    __fastios;
    int N;
    cin >> N;
    basic_string<char> bsc1;
    cin.ignore();
    for(int i = 1; i <= N; i++)
    {
        getline(cin,bsc1);
        cout << i << ". " << bsc1 << '\n';
    }
}

// solve