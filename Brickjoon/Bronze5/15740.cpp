#include <bits/stdc++.h>

using namespace std;

void Nout(string log_data,string option = "")
{
	cout << "\ncout : " << log_data << option;
}

void Nout_vec(vector<int>& vec1,string option = "")
{
	for (int i = 0; i < vec1.size(); i++)
	{
		cout << vec1.at(i) << option;
	}
}

string num_iflogic1(string num_data)
{
	if (num_data.at(0) == '-')
		return "-";
	else
		return "+";
}

void convert_str_to_int1(vector<int>& vec1,string str1)
{
	if (num_iflogic1(str1) == "-")
	{
		for (int i = 0; i < str1.length() - 1; i++)
			vec1.push_back(-(int(str1.at(i + 1)) - '0'));
		Nout("\n- detectd : ");
	}
	else
	{
		for (int i = 0; i < str1.length(); i++)
			vec1.push_back(str1.at(i) - '0');
		Nout("\n+ detected : ");
	}
}

int main()
{
		clock_t time1 = clock();
		// option 
		cin.tie(nullptr);
		ios_base::sync_with_stdio(false);
		// code 
		string str, str2;
		cin >> str >> str2;
		vector <int> main_num1, main_num2;

		main_num1.reserve(str.length());
		main_num2.reserve(str2.length());

		convert_str_to_int1(main_num1, str);
		Nout_vec(main_num1, " ");
		convert_str_to_int1(main_num2, str2);
		Nout_vec(main_num2, " ");

		if (main_num1.max_size() <= main_num2.max_size())
		{
			main_num2.reserve(10002);
			for (int i = 0; i < main_num1.size(); i++)
			{
				main_num2.at(main_num2.size() - i) += main_num1.at(main_num1.size() - i);
				cout << main_num2.at(main_num2.size() - i) << '\n';
			}
		}
		else
		{

		}
		// now combined
		cout << "time : " << (double((clock() - time1) / CLOCKS_PER_SEC));
		return 0;
}
