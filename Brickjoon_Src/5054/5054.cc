#include <bits/stdc++.h>
using namespace std;
namespace rng = ranges;

int main()
{
    int t, n, t2, a, b;
    cin >> t;
    while(t--)
    {
        cin >> n >> t2;
        a = t2;
        b = t2;
        for(int i = 0; i < n-1; i++)
        {
            cin >> t2;
            if(t2 < a) a = t2;
            if(t2 > b) b = t2;
        }
        cout << (b-a)*2 << '\n';
    }
}

// solve