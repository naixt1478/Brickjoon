#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[5];
    for(int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    cout << min(a[3],a[4]) + min({a[0],a[1],a[2]}) - 50;
}

// solve