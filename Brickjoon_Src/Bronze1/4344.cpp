#include <iostream>

using namespace std;

int main()
{
    // option
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(3);
    // end
    double a, b, c[1000] {0};
    cin >> a;
    for(int i = 0; i < a; i++)
    {
        cin >> b;
        double d{0},f{0};
        for(int j = 0; j < b; j++)
        {
            cin >> c[j];
            d += c[j];
        }
        for(int j = 0; j < b; j++)
        {
            if((d/b) < c[j])
            {
                f++;
            }
        }
        cout << (f*100)/b << "%" << "\n";
    }
}

// solved