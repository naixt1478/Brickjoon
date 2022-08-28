#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,i1,i2{},i3,i4;
    cin >> i1 >> T;
    while(T--)
    {
        cin >> i3 >> i4;
        i2 += i3*i4;
    }
    if(i2==i1) cout << "Yes";
    else cout << "No";
}

// solve