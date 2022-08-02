#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template <typename T>
using V = vector<T>;

struct _bsc1i3
{
	basic_string<char> bsc1;
	int a, b, c;
};

bool comp1(const _bsc1i3& a, const _bsc1i3& b)
{
	if (a.a == b.a)
	{
		if (a.b == b.b) return a.c > b.c;
		else return a.b > b.b;
	}
	else return a.a > b.a;
}

int main()
{
	__fastios;
	basic_string<char> bsc1;
	int n,a,b,c;
	cin >> n;
	V<_bsc1i3> vbsc1i3_1;
	for (int i = 0; i < n; i++)
	{
		cin >> bsc1 >> a >> b >> c;
		vbsc1i3_1.emplace_back(bsc1,c,b,a);
	}
	rng::sort(vbsc1i3_1,comp1);
	cout << vbsc1i3_1[0].bsc1 << '\n' << vbsc1i3_1[vbsc1i3_1.size() - 1].bsc1;
}

// solve
