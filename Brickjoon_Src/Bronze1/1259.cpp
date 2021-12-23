#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    while (getline(cin, s1))
    {
        if (s1 == "0") break;
        for (int i = 0; i < s1.size() / 2 + 1; i++)
        {
            if (s1[i] == s1[s1.size() - 1 - i])
            {
                s2 = "yes";
            }
            else
            {
                s2 = "no";
                break;
            }
        }
        cout << s2 << '\n';
    }
}

// solve