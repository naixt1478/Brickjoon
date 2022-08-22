#include "bits/stdc++.h"
using namespace std;

int main()
{
    int a;
    vector<int> vi1(31);
    for(int i = 0; i < 28; i++) 
    {
        cin >> a;
        vi1[a] = 1;
    }
    for(int i = 1; i <= 30; i++)
    {
        if(!vi1[i]) cout << i << '\n';
    }
}

// solve