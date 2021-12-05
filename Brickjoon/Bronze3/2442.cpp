#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        for (int j = a - i-1; 0 < j; j--)
            cout << ' ';
        for (int j = i*2; 0 <= j; j--)
            cout << "*";
        cout << '\n';
    }
}
//solved