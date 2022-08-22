#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a(0),b(0),temp;
    for(int i = 0; i< 4; i++)
    {
        cin >> temp;
        a += temp;
    }
    for(int i = 0; i< 4; i++)
    {
        cin >> temp;
        b += temp;
    }
    if(a > b)
        cout << a;
    else if (a < b)
        cout << b;
    else
        cout << a;
}

// solve