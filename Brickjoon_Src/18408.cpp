#include <bits/stdc++.h>
using namespace std;
namespace rng = ranges;

int main()
{
    vector<int> vi1(3);
    for(auto& i1 : vi1)
    {
        cin >> i1;
    }
    if(rng::count(vi1,1) > rng::count(vi1,2))
    {
        cout << 1;
    }
    else cout << 2;
}

// solve