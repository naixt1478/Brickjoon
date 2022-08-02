#include <bits/stdc++.h>
using namespace std;

int Stop(stack<int>& s1)
{
	if(s1.empty()) return 0;
	else return s1.top();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int N, t, j{}, work{1};
	cin >> N;
	stack<int> s1;
	vector<char> vc1;
	while(N--)
	{
		cin >> t;
		while(Stop(s1) < t)
		{
			vc1.emplace_back('+');
			s1.push(++j);
		}
		if(Stop(s1) == t)
		{
			vc1.emplace_back('-');
			s1.pop();
		}
		else
		{
			work = 0;
			break;
		}
	}
	if(work) for(auto& c1 : vc1) cout << c1 << '\n';
	else cout << "NO";
}

// solve