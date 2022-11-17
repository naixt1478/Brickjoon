#include <iostream>

using namespace std;

int main()
{
    int a(5),b(0),c(0);
    while(a--)
    {
        cin >> b;
        if(b <= 40)
        {
            c += 40;
        }
        else
        {
            c += b;
        }
    }
    cout << (c/5);
}

// solve