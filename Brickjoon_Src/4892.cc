#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n,a{0};
    while(cin >> n,n != 0)
    {
        a++;
        if(n*3%2 == 0)
        {
            cout << a << ". " << "even " << n/2 << '\n';
        }
        else
        {
            cout << a << ". " << "odd " << ((((n*3)/2)+1)*3)/9 << '\n';
        }
    }
}

// solve