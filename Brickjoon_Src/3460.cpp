#include "bits/stdc++.h"
using namespace std;

void b1(int n)
{
    string::size_type a = 0;
    basic_string<char> bsc;
    while (n > 0)
    {
        if (n % 2 == 1) bsc.push_back('1');
        else bsc.push_back('0');
        n /= 2;
    }
    int m = bsc.length();
    for(int i = 0; i < m; i++)
    {
        if (bsc[i] == '1') cout << i << ' ';
    }
}

int main()
{
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        b1(N);
        cout << '\n';
    }
}

// solve