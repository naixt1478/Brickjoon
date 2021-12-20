#include <bits/stdc++.h>
using namespace std;

void vin(vector<int>& vec1)
{
    int a = vec1.size(), i(0);
    while (cin >> vec1[i])
    {
        if (i == a) return;
        i++;
    }
}
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n;
    vector<int> a(n);
    vin(a);
    cin >> m;
    vector<int> b(m);
    vin(b);
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++)
    {
        cout << binary_search(a.begin(), a.end(), b[i]) << ' ';
    }
}