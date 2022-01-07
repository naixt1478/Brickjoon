#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::locale::global(std::locale("kor"));
	wstring str;
	wcin.imbue(std::locale("kor"));
	wcout.imbue(std::locale("kor"));
	wcin >> str;
	cout << int(str[0])-44031 << '\n';
}

// solving in progress..