#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int L(s.length());
    if(L == 2)
        cout << (s[0] + s[1] - '0' - '0');
    else if (L == 3)
        cout << (s[1] == '0' ? (10 + (s[2] - '0')) : (10 + (s[0] - '0')));
    else
        cout << 20;
        
}

// solve