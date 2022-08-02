/*
#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

void s1()
{
	int i, a, s{};
	cin >> i;
	priority_queue<int, vector<int>, rng::greater> pq1;
	priority_queue<int, vector<int>> pq2;
	char c;
	while (i--)
	{
		cin >> c;
		if (c == 'I')
		{
			cin >> a;
			pq1.emplace(a);
			pq2.emplace(a);
			s++;
		}
		else
		{
			cin >> a;
			if (s >= 1)
			{
				if (a == -1) pq1.pop();
				else pq2.pop();
				s--;
			}
		}
	}
	if (s<=0) cout << "EMPTY\n";
	else
	{
		cout << pq2.top() << ' ' << pq1.top() << '\n';
	}
}

int main()
{
	__fastios;
	int T;
	cin >> T;
	while (T--)
	{
		s1();
	}
}
*/
// priority_queue solving
// not pass solving
#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

void s1()
{
	int i, a;
	cin >> i;
	multiset<int> ms1;
	char c;
	while (i--)
	{
		cin >> c;
		if (c == 'I')
		{
			cin >> a;
			ms1.emplace(a);
		}
		else
		{
			cin >> a;
			if (!ms1.empty())
			{
				if (a == -1) ms1.erase(ms1.begin());
				else ms1.erase(rng::prev(ms1.end()));
			}
		}
	}
	if (ms1.empty()) cout << "EMPTY\n";
	else
	{
		cout << *rng::prev(ms1.end()) << ' ' << *ms1.begin() << '\n';
	}
}

int main()
{
	__fastios;
	int T;
	cin >> T;
	while (T--)
	{
		s1();
	}
}
// multiset solving
/*
#include "bits/stdc++.h"
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;

void s1()
{
	int i,a;
	cin >> i;
	multimap<int,int> mm1;
	char c;
	while(i--)
	{
		cin >> c;
		if(c == 'I')
		{
			cin >> a;
			mm1.emplace(a, a);
		}
		else
		{
			cin >> a;
			if (!mm1.empty())
			{
				if (a == -1) mm1.erase(mm1.begin());
				else mm1.erase(rng::prev(mm1.end()));
			}
		}
	}
	if (mm1.empty()) cout << "EMPTY\n";
	else
	{
		cout << rng::prev(mm1.end())->first << ' ' << mm1.begin()->first << '\n';
	}
}

int main()
{
	__fastios;
	int T;
	cin >> T;
	while(T--)
	{
		s1();
	}
}
*/
// multimap solving