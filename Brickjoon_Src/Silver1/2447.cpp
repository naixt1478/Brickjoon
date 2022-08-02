#include <bits/stdc++.h>
using namespace std;

char cube(int n, int n2, int n3)
{
	if (n2 / n == 1 && n3 / n == 1) return ' ';
	else if (n == 1) return '*';
	else return cube(n / 3, n2 % n, n3 % n);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, i{};
	cin >> n;
	vector<basic_string<char>> vs1(n, basic_string<char>(n + 1, '\n'));
	for (auto& s1 : vs1)
	{
		for (int j = 0; j < n; j++) s1[j] = (cube(n / 3, j, i));
		i++;
	}
	for (auto& s : vs1) cout << s;
}

// 2D vector solve
// solve
// cout solve
/*#include <bits/stdc++.h>
using namespace std;

void cube(int n, int n2, int n3)
{
	if (n2 / n == 1 && n3 / n == 1) cout << " ";
	else if (n == 1) cout << "*";
	else cube(n / 3, n2 % n, n3 % n);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cube(n / 3, j, i);
		cout << "\n";
	}
}*/
