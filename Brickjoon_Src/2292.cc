#include <iostream>

using namespace std;

int main()
{
    int N,b=1,i=1;
    cin >> N;
    while(true)
    {
        if(N > b)
        {
            b += (i*6);
            i++;
        }
        else
            break;
    }
    cout << i;
}

// solve