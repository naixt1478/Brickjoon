#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,a,b,sum1{};
    cin >> N;
    while(N--)
    {
        cin >> a >> b;
        sum1 += b%a;
    }
    cout << sum1;
}

// solve