#include <bits/stdc++.h>
using namespace std;

void loop1(int a,int b)
{
    string s1;
    if(a%2!=0) s1 = "+-";
    else s1 = "|.";
    if(a==1||a==2) 
    {
        cout << ".."; 
        b--;
    }
    while(b--) cout << s1;
    cout << s1[0] << '\n';
    
}

int main()
{
    int T,R,C;
    cin >> T;
    for(int i = 1; i <= T; i++)
    {
        cin >> R >> C;
        cout << "Case #" << i << ":\n";
        for(int j = 0; j <= R*2; j++)
        {
            loop1(j+1,C);
        }
    }
}

// solve