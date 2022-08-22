#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n,a;
    cin >> n;
    while(n--)
    {
        cin >> a;
        cout << "Pairs for " << a << ": ";
        for(int i = 1; i < a-i; i++)
        {
            cout << i << ' ' << a-i;
            if(i+1 < a-(i+1)) cout << ", ";
        }
        cout << '\n';
    }
}

// solve