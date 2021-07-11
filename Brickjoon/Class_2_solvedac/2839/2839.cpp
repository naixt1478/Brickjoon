#include <iostream>

using namespace std;

int main()
{
    int N, c = 0, i = 1;
    cin >> N;
    while (1)
    {
        c += 5;
        if (N <= c)
            break;
        i++;
    }
    while (1)
    {
        if (N == c)
            break;
        else if (0 > N - c)
        {
            i--;
            c -= 5;
        }
        else if (0 > c)
        {
            i = -1;
            break;
        }
        else if (((N - c) % 3) != 0)
        {
            i--;
            c -= 5;
        }
        else
        {
            i += (N - c) / 3;
            break;
        }
    }
    cout << i;
}