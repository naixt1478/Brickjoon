#include <bits/stdc++.h>
#define __fastios ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
namespace rng = ranges;
template <typename T>
using bs = basic_string<T>;

int main()
{
	__fastios;
	setlocale(LC_ALL, "");
	int max1{};
	bs<wchar_t> bsc1, bsc2;
	wcin >> bsc1 >> bsc2;
	wstring_convert<codecvt_utf16<wchar_t>, wchar_t> utf16Conv1;
	auto utf16s1 = utf16Conv1.to_bytes(bsc1.c_str());
	auto utf16s2 = utf16Conv1.to_bytes(bsc2.c_str());
	vector<vector<int>> vvi1(utf16s1.length()+1, vector<int>(utf16s2.length()+1));
	for (size_t i = 1; i <= utf16s1.length(); i++)
	{
		for (size_t j = 1; j <= utf16s2.length(); j++)
		{
			if (utf16s1[i - 1] == utf16s2[j - 1])
			{
				vvi1[i][j] = vvi1[i - 1][j - 1] + 1;
				if (vvi1[i][j] > max1) max1 = vvi1[i][j];
			}
			else vvi1[i][j] = rng::max(vvi1[i-1][j], vvi1[i][j-1]);
		}
	}
	cout << max1;
}
