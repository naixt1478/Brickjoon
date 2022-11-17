#include <bits/stdc++.h>

using namespace std;

void s(int a,int b)
{
    for(int i = 0; i < b-a; i++)
        cout << ' ';
    for(int j = 0; j < (a-1)*2+1; j++)
        cout << '*';
    cout << '\n';
}

int main()
{
    int n;
    cin >> n;
    for(int i = n; i > 1; i--)
        s(i,n);
    for(int i = 1; i <= n; ++i)
        s(i,n);
}

// solve