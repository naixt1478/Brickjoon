#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    stringstream ss(str);
    while(getline(ss, str, '-'))
    {
        cout << str[0];
    }
}

// solve