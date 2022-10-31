#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a{};
    cin >> n;
    vector<int> vi1(11);
    vi1[n]++;
    for(int i = 10; i > 1; i--)
    {
        while(vi1[i] > 0)
        {
            a += i/2 * (i/2+i%2);
            vi1[i/2]++;
            vi1[i/2 + i%2]++;
            vi1[i]--;
        }
    }
    cout << a;
}

// solve