#include <iostream>

using namespace std;

int main()
{
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int b = a[0] + a[1] + a[2] + a[3];
    cout << b/60 << '\n' << b%60;
}

// solve