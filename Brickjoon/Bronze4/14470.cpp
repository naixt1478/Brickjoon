#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    if(a<0)
        cout << (a*c*-1)+d+(b*e);
    else
        cout << (b-a)*e;
}