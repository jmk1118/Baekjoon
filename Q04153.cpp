#include <iostream>

int main(void)
{
	int x, y, z;
	std::cin >> x >> y >> z;

	while (x != 0 && y != 0 && z != 00)
	{
		if (x > y)
			if (x > z)
				if (x * x == y * y + z * z)
					std::cout << "right\n";
				else
					std::cout << "wrong\n";
			else
				if (z * z == x * x + y * y)
					std::cout << "right\n";
				else
					std::cout << "wrong\n";
		else
			if (y > z)
				if (y * y == x * x + z * z)
					std::cout << "right\n";
				else
					std::cout << "wrong\n";
			else
				if (z * z == x * x + y * y)
					std::cout << "right\n";
				else
					std::cout << "wrong\n";

		std::cin >> x >> y >> z;
	}
}