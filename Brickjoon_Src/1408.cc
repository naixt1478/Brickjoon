#include "bits/stdc++.h"
using namespace std;

int main()
{
    vector<int> vi1 = {3600,60,1};
    int sum1{},sum2{},sum3;
    istringstream iss1,iss2;
    basic_string<char> bsc,bsc1,bsc2;
    getline(cin,bsc1);
    getline(cin,bsc2);
    iss1.str(bsc1);
    iss2.str(bsc2);
    for(int i = 0; getline(iss1,bsc,':'); i++) sum1 += stoi(bsc) * vi1[i];
    for(int i = 0; getline(iss2,bsc,':'); i++) sum2 += stoi(bsc) * vi1[i];
    sum3 = sum2 - sum1;
    if(sum3 < 0) sum3 += 24*3600;
    for(int i = 0; i < 3; i++)
    {
        if(sum3/vi1[i] <= 9) cout << 0; 
        cout << sum3/vi1[i] << (i!=2?":":"");
        sum3 %= vi1[i];
    }
}