#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, b = 0, f = 1, buf;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		buf = b + f;
		b = f;
		f = buf;
	}
	cout << f;
}

// for loop code 
// solve
// memo function code
/*
#include <bits/stdc++.h>
using namespace std;

vector<int> fmemo(45);
int fnum(int n)
{
	if (n < 2) return n;
	if(fmemo[n] != 0) return fmemo[n];
	fmemo[n] = fnum(n - 1) + fnum(n - 2);
	return fmemo[n];
}

int main()
{
	fmemo[1] = 1;
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	cin >> n;
	cout << fnum(n);
}
*/
