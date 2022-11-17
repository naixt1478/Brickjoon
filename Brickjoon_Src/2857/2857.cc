#include "bits/stdc++.h"
using namespace std;

int main()
{
    int i1 = 0;
    basic_string<char> bsc;
    for(int i = 1; i <= 5; i++)
    {
        cin >> bsc;
        if(bsc.find("FBI", 0)!=string::npos) 
        {
            i1 = 1;
            cout << i << ' ';
        }
    }
    if(i1 == 0) cout << "HE GOT AWAY!";
}

// solve