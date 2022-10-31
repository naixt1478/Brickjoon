#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T,N{},sum1{};
    cin >> T;
    while(T--)
    {
        sum1 = 0;
        cin >> N;
        for(int i = 1; i <= N; i+=2) sum1 += i;
        cout << sum1 << '\n';
    }
}

// solve