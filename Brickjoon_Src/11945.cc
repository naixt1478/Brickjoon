#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    basic_string<char> bsc1;
    cin >> a >> b;
    while(a--)
    {
        cin >> bsc1;
        for(int i = b-1; i >= 0; i--)
        {
            cout << bsc1[i];
        }
        cout << '\n';
    }
}

// solve