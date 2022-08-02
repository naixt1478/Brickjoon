#include <bits/stdc++.h>
using namespace std;
namespace rng = ranges;

int main()
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	cout << rng::min(A + D, B + C);
}

// solve