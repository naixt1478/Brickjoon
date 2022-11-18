#include <iostream>

using namespace std;

int main()
{
    int t,a=0,b=0;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        a=0,b=0;
        cin >> a >> b;
        cout << "Case #" << i << ": " << a << " + " << b << " = " << (a+b) << "\n";
    }
    
}

// solve