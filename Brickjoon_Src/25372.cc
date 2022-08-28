#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int main()
{
    __fastios;
    int i1;
    basic_string<char> s1;
    cin >> i1;
    while(i1--)
    {
        cin >> s1;
        if(6 <= s1.length() && s1.length() <= 9) cout << "yes\n";
        else cout << "no\n";
    }
}

// solve