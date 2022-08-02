/*
#include <bits/stdc++.h>
using namespace std;
namespace rng = ranges;
typedef vector<int> vi;

int p_ni(int i) { return (i - 1) / 2; }
int left_ni(int i) { return (2 * i + 1); }
int right_ni(int i) { return (2 * i + 2); }

void push(vi& HEAP1, int& input)
{
	HEAP1.emplace_back(input);
	int cindex = HEAP1.size() - 1;
	while (cindex != 0 && abs(HEAP1[p_ni(cindex)]) >= abs(HEAP1[cindex]))
	{
		if(abs(HEAP1[p_ni(cindex)]) == abs(HEAP1[cindex]))
		{
			if (HEAP1[p_ni(cindex)] > HEAP1[cindex])
			{
				rng::swap(HEAP1[p_ni(cindex)], HEAP1[cindex]);
				cindex = p_ni(cindex);
			}
			else break;
		}
		else
		{
			rng::swap(HEAP1[p_ni(cindex)], HEAP1[cindex]);
			cindex = p_ni(cindex);
		}
	}
}

void pop_after(vi& HEAP1, int i)
{
	int lndex = left_ni(i);
	int rndex = right_ni(i);
	int result = i;
	if (lndex < HEAP1.size() && abs(HEAP1[lndex]) <= abs(HEAP1[i]))
	{
		if(abs(HEAP1[lndex]) == abs(HEAP1[i]))
		{
			if(HEAP1[lndex] <= HEAP1[i]) result = lndex;
		}
		else result = lndex;
	}
	if (rndex < HEAP1.size() && abs(HEAP1[rndex]) <= abs(HEAP1[result]))
	{
		if(abs(HEAP1[rndex]) == abs(HEAP1[result]))
		{
			if(HEAP1[rndex] < HEAP1[result]) result = rndex;
		}
		else result = rndex;
	}
	if (i != result)
	{
		rng::swap(HEAP1[result], HEAP1[i]);
		pop_after(HEAP1, result);
	}
}

int pop(vi& HEAP1)
{
	if (HEAP1.empty()) return 0;
	else
	{
		int ret = HEAP1[0];
		rng::swap(HEAP1[0], HEAP1[(HEAP1.size() - 1)]);
		HEAP1.pop_back();
		pop_after(HEAP1, 0);
		return ret;
	}
}


int main()
{
	vi HEAP1, output;
	HEAP1.reserve(100001);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int N, t{};
	cin >> N;
	while (N--)
	{
		cin >> t;
		if (t == 0) output.emplace_back(pop(HEAP1));
		else push(HEAP1, t);
	}
	for (auto& out : output) cout << out << '\n';
}
*/
// not using STL solve
// solve
// using STL solve
#include <bits/stdc++.h>
#define _FASTIOS ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;

class compare
{
public:
	bool operator()(const auto& left,const auto& right)
	{
		if(abs(left) ^ abs(right)) return abs(left) > abs(right);
		return left > right;
	}
};

int main()
{
	_FASTIOS
	int N, T;
	priority_queue<int, vector<int>, compare> pq1;
	cin >> N;
	while (N--)
	{
		cin >> T;
		if (T == 0)
		{
			if (pq1.empty()) cout << 0 << '\n';
			else
			{
				cout << pq1.top() << '\n';
				pq1.pop();
			}
		}
		else pq1.push(T);
	}
}