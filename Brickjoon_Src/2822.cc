#include <bits/stdc++.h>
using namespace std;
namespace rng = ranges;

int main()
{
    int a,sum{};
    vector<int> vi1;
    vector<pair<int,int>> vpii1;
    for(int i = 1; i <= 8; i++)
    {
        cin >> a;
        vpii1.emplace_back(a,i);
    }
    rng::sort(vpii1, rng::greater());
    for(int i = 0; i < 5; i++)
    {
        vi1.emplace_back(vpii1[i].second);
        sum += vpii1[i].first;
    }
    rng::sort(vi1);
    cout << sum << '\n';
    for(int i = 0; i < 5; i++)
    {
        cout << vi1[i] << ' ';
    }
}

// solve