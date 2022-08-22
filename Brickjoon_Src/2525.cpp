#include <iostream>

using namespace std;

int main()
{
    int a, b, t;
    cin >> a >> b;
    b += a * 60;
    cin >> t;
    b += t;
    if (b >= 24 * 60)
        b -= 24 * 60;
    cout << b / 60 << " " << b % 60;
}

// solve