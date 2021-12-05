#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // inital
    int a, b;
    cin >> a >> b;
    int a1 = a, b1 = b;
    string str, str2;
    cin >> str >> str2;

    // convert str -> int
    vector<int> num1, num2;
    while (a1--)
    {
        num1.push_back(int(str.at(a1) - '0'));
    }
    while (b1--)
    {
        num2.push_back(int(str.at(b1) - '0'));
    }
    cout << "test : ";
    for(int i = 0; i < a; i++)
    {
        cout << num1[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < b; i++)
    {
        cout << num2[i] << ' ';
    }
}