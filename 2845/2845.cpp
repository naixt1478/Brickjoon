#include <iostream>

int main()
{
	int a,b,i,n;
	std::cin >> a >> b;
	for(i = 0; i < 5; i++)
	{
		std::cin >> n;
		std::cout << n-a*b << "\n";
	}
}

//solved