#include <iostream>

using namespace std;

int main()
{
    int a,b,c,r,t;
    cin >> t;
    a = t/300;
    r = t%300;
    b = r/60;
    r = t%60;
    c = r/10;
    r = r%10;
    if(r == 0)
        cout << a << " " << b << " " << c;
    else
        cout << -1;
}

// solve