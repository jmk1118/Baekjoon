#include <iostream>

int main(void)
{
	int n;
	std::cin >> n;

	if (n >= 3)
	{
		if (n == 4 || n == 7)
			std::cout << -1;
		else if ((n % 5) % 3 == 0)
			std::cout << n / 5 + (n % 5) / 3;
		else if ((n % 5) % 3 == 1)
			std::cout << ((n / 5) - 1) + ((n % 5) + 5) / 3;
		else if ((n % 5) % 3 == 2)
			std::cout << ((n / 5) - 2) + ((n % 5) + 10) / 3;
	}
	else
		std::cout << -1;
}