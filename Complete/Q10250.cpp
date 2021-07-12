#include <iostream>

int main(void)
{
	int t;
	int h, w, n;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		std::cin >> h >> w >> n;

		if (n % h == 0)
		{
			std::cout << h;

			if (n / h > 9)
				std::cout << n / h << "\n";
			else
				std::cout << 0 << n / h << "\n";
		}
		else
		{
			std::cout << n % h;

			if (n / h >= 9)
				std::cout << n / h + 1 << "\n";
			else
				std::cout << 0 << n / h + 1 << "\n";
		}
	}
}