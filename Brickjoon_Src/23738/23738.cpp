#include <bits/stdc++.h>

using namespace std;

string matching(char s,string s2 = "")
{
    if(s == 'B') s2 = "v";
    else if(s == 'E') s2 = "ye";
    else if(s == 'H') s2 = "n";
    else if(s == 'P') s2 = "r";
    else if(s == 'C') s2 = "s";
    else if(s == 'Y') s2 = "u";
    else if(s == 'X') s2 = "h";
    else s2 = char(s + ' ');
    return s2;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    for(int i = 0; i < str.length(); i++)
    {
        cout << matching(str[i]);
    } 
}

// solve