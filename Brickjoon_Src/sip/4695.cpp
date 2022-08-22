#include <bits/stdc++.h>
using namespace std;
int main()
{

}
/*#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template<typename T>
using bs = basic_string<T>;

map<bs<char>, int> solve(bs<char> bsc1,int length)
{
	int _i{};
	map<bs<char>, int> _mbsci;
	for (int i = 0; i <= (static_cast<long long int>(bsc1.length()) - length); i++)
	{
		bs<char> _bsc = {};
		for (int j = 0; j < length; j++)
		{
			_bsc += bsc1[i + j];
			if (bsc1[i + j] < 'A' || bsc1[i + j] > 'Z')
			{
				_i = 1;
				break;
			}
		}
		if (_i)
		{
			_i = 0;
			continue;
		}
		else if (_mbsci.contains(_bsc)) _mbsci.at(_bsc)++;
		else _mbsci.emplace(_bsc, 1);
	}
	return _mbsci;
}

bool comp(pair<bs<char>, int>& _A, pair<bs<char>, int>& _B)
{
	if (_A.second == _B.second)
	{
		return _A.first < _B.first;
	}
	return _A.second > _B.second;
}

int main()
{
	__fastios;
	map<bs<char>, int> mbsci1;
	bs<char> bsc1;
	getline(cin, bsc1);
	rng::transform(bsc1.begin(), bsc1.end(), bsc1.begin(), [](unsigned char c) {return toupper(c); });
	for (int i = 1; i <= 5; i++)
	{
		int max1 = { -1 }, cnt{0};
		mbsci1 = solve(bsc1, i);
		vector<pair<bs<char>, int>> vpbsci1(mbsci1.begin(), mbsci1.end());
		if (vpbsci1.size() == 0) continue;
		else
		{
			cout << "Analysis for Letter Sequences of Length " << i
			<< "\n-----------------------------------------\n";
		}
		rng::sort(vpbsci1, comp);
		for(int j = 0; j < vpbsci1.size(); j++)
		{
			auto& [_bsc, _i] = vpbsci1[j];
			if (max1 != _i)
			{
				max1 = _i;
				cnt++;
				if (cnt > 5) break;
				cout << "Frequency = " << max1 << ", "
					<< "Sequence(s) = (";
			}
			cout << _bsc << (j + 1 >= vpbsci1.size() || _i != vpbsci1[j + 1].second ? ")\n" : ",");
		}
		cout << '\n';
	}
}
*/