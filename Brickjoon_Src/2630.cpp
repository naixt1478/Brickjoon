#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
int _i1, _i2;


void s1(vector<vector<int>>& vvi1, int a, int x, int y)
{
    int a2 = a / 2, cnt1{}, cnt2{};
    vector<pair<pair<int, int>, pair<int, int>>> pvi1 =
    {
        pair(pair(x,x+a2),pair(y,y+a2)),
        pair(pair(x+a2,x+a),pair(y,y+a2)),
        pair(pair(x,x+a2),pair(y+a2,y+a)),
        pair(pair(x+a2,x+a),pair(y+a2,y+a))
    };
    for (auto [_x, _y] : pvi1)
    {
        int bf1 = -1;
        for (int i = _x.first; i < _x.second; i++)
        {
            for (int j = _y.first; j < _y.second; j++)
            {
                if (bf1 != -1 && bf1 != vvi1[i][j])
                {
                    s1(vvi1, a / 2, _x.first, _y.first);
                    bf1 = -2;
                    break;
                }
                else bf1 = vvi1[i][j];
            }
            if (bf1 == -2) break;
        }
        if (bf1 != -2 && bf1 == 0)
        {
            _i1++;
            cnt1++;
        }
        else if (bf1 != -2 && bf1 == 1)
        {
            _i2++;
            cnt2++;
        }
    }
    if (cnt1 == 4) _i1 -= 3;
    else if (cnt2 == 4) _i2 -= 3;
}

int main()
{
    __fastios;
    int n;
    cin >> n;
    vector<vector<int>> vvi1(n, vector<int>(n));
    for (auto& vi1 : vvi1)
        for (auto& i1 : vi1) cin >> i1;
    s1(vvi1, n, 0, 0);
    cout << _i1 << '\n' << _i2;
}

// solve