#include "bits/stdc++.h"
#define __fastios std::ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

int main()
{
    __fastios;
    int n;
    cin >> n;
    vector<int> vi1(n);
    for (int& i1 : vi1) cin >> i1;
    vector<int> vi2 = vi1;
    for (int i = 0; i < n; i++)
    {
        vi1[i] = vi2[i];
        if(i+3 < n) vi2[i + 3] = rng::max(vi2[i + 3], (vi1[i + 3] + vi1[i + 1] + vi1[i]));
        if (i + 2 < n) vi2[i + 2] = rng::max(vi2[i + 2], (vi1[i + 2] + vi1[i]));
    	if (i + 1 == n - 1) vi2[i + 1] = rng::max(vi2[i + 1], (vi1[i + 1] + vi1[i]));
    }
    cout << vi1[n - 1];
}

// solve