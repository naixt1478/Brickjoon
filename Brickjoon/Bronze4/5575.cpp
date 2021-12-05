#include <bits/stdc++.h>

using namespace std;

void s1()
{
    vector <int> vec1(6);
    for(int i = 0; i < 6; i++) cin >> vec1[i];
    int a{},b{};
    a = (vec1[0]*3600) + (vec1[1] * 60) + (vec1[2]);
    b = (vec1[3]*3600) + (vec1[4] * 60) + (vec1[5]);
    b -= a;
    cout << (b/3600) << ' ' << ((b%3600)/60) << ' ' << ((b%3600)%60) << '\n';
}

int main()
{
    int n(3);
    while(n--) s1();
}