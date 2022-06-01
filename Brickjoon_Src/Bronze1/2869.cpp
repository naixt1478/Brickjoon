#include <iostream>

int main()
{
	long A, B, V, a = 0;
	std::cin >> A >> B >> V;
	if ((V - A) % (A - B) == 0)
	{
		a = (V - A) / (A - B);
	}
	else
	{
		a = (V - A) / (A - B) + 1;
	}
	std::cout << a + 1;
}

// solve