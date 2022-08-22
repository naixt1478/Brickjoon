#include <bits/stdc++.h>
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
using namespace std;
namespace rng = ranges;
typedef long long int lli;
typedef basic_string<char> bsc;

int main()
{
	_FASTIOS;
	int a,b,c;
	vector<bsc> vbsc1 = {"Error","Equilateral","Isosceles","Scalene"};
	cin >> a >> b >> c;
	if (a + b + c != 180) cout << vbsc1[0];
	else if (a == 60 && a == b) cout << vbsc1[1];
	else if (a == b || b == c || c == a) cout << vbsc1[2];
	else cout << vbsc1[3];
}

// solve