#include <iostream>
#include <string>
using namespace std;
u8string s1;

int a,b,c;

int main(void)
{
    cin >> s1;
    printf("%d", ((s1[0] & 31) << 12) + ((s1[1] & 127) << 6) + (s1[2] & 127) - 44031);
    return 0;
}