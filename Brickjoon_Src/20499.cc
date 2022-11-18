#include <bits/stdc++.h>

int main()
{
    int a[3],i=3;
    while(i--)
    {
        std::cin >> a[i];
        std::cin.ignore(256, '/');
    }
    std::cout << (a[0]+a[2] < a[1] || !a[1] ? "hasu" : "gosu");
}

// solve