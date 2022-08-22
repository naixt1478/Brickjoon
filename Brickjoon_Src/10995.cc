#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N+N; j++)
        {
            if((i+j)%2==0) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}

// solve