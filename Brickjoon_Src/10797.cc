#include <iostream>

using namespace std;

int main()
{
    int a,b,c(0);
    cin >> a;
    for(int i = 0; i < 5; i++)
    {
        cin >> b;
        if(a == b)
            c++;
    }
    cout << c;
}

// solve