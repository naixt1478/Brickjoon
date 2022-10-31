#include <bits/stdc++.h>

using namespace std;

int Rev(int a)
{
    string b = to_string(a);
    reverse(b.begin(), b.end());
    return stoi(b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << Rev(Rev(a) + Rev(b));
}

// solve