#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main()
{
    long m1, m2;
    cin >> m1;
    vector<long> N1(m1);
    for(int i = 0; i < m1; i++)
    {
        cin >> N1[i];
    }
    sort(N1.begin(), N1.end());
    cin >> m2;
    vector<long> N2(m2);
    for(long i = 0; i < m2; i++)
    {
        cin >> N2[i];
    }
    for(int i = 0; i < m2; i++)
    {
        if (binary_search(N1.begin(), N1.end(), N2[i]))
            cout << 1 << '\n';
        else
            cout << 0 << "\n";
    }
}

// solve