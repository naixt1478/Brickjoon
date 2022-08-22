#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,f;
    cin >> a >> b;
    c = (b%10);
    d = (b%100);
    cout << a*c << "\n" << (a*(d-c)/10) << "\n" << (a*(b-d)/100) << "\n" << a*b;
}

// solve