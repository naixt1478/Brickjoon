#include <bits/stdc++.h>

using namespace std;

int u1(int a,int b)
{
    if(b == 0)
        return a;
    else
        return u1(b, a%b);
}

int main()
{
    int n,a,b,B;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        B = u1(a,b);
        cout << (a*b)/B << '\n';
    }
}

// solve