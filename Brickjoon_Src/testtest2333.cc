#include <iostream>
#include <string>
using namespace std;
int N,M,C;

int main()
{
    string s1;
    cin >> N >> M;
    while(N--)
    {
        getline(cin, s1);
        if(s1 == "<CENTER>") C = 1;
        else if(s1 == "<RIGHT>") C = 2;
        else if(s1 == "</CENTER>") C = 0;
        else if(s1 == "</RIGHT>") C = 0;
        if(s1.length() > M)
        if(C == 0)
        {
            
        }
        else if (C == 1)
        {
            
        }
        else
        {
            
        }
    }
    return 0;
}