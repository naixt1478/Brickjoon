#include "bits/stdc++.h"
using namespace std;

int main()
{
    cout << fixed;
    cout.precision(1);
    int T,sum1,n,a;
    float f1{},f2;
    cin >> T;
    while(T--)
    {
        sum1 = 0,f1 = 0;
        cin >> n;
        while(n--)
        {
            cin >> a >> f2;
            sum1 += a;
            f1 += a*f2;
        }
        cout << sum1 << ' ' << f1/sum1 << '\n';
    }
}

// solve