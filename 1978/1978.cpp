#include <iostream>

int main()
{
	int n,i,a,c = 0;
	std::cin >> n;
	for(i = 0; i < n; i++)
	{
		std::cin >> a;
		if(a == 1)
		{
			c++;
		}
		else
		{
		for(int b = 2; b<a; b++)
			{
				if(a % b == 0)
				{
					c++;
					break;
				}
			}
		}
	}
	std::cout << n-c;
}

// solved