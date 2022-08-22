#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
    __fastios;
    int T;
    vector<int> vi1(10);
    cin >> T;
    while(T--)
    {
        for(auto& i1 : vi1) cin >> i1;
        rng::sort(vi1,rng::greater());
        cout << vi1[2] << '\n';
    }
}

// solve