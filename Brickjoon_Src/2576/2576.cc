#include <bits/stdc++.h>

using namespace std;

int main()
{
    int b,r(0),s(0),c(0);
    for(int i = 0; i < 7; i++)
    {
        cin >> b;
        if(b%2 != 0)
        {
            r += b;
            if(c==0) 
                s=b;
            else if (b <= s) 
                s = b;
            
            c = 1;
        }
    }
    if(r == 0) 
        cout << -1;
    else
        cout << r << '\n' << s;
}

// solve