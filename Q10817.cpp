#include <iostream>

int main(void)
{
	int a, b, c;
	std::cin >> a >> b >> c;

	if (a >= b)
		if (a >= c)
			if (b >= c)
				std::cout << b;
			else
				std::cout << c;
		else
			std::cout << a;
	else
		if (b >= c)
			if (a >= c)
				std::cout << a;
			else
				std::cout << c;
		else
			std::cout << b;
}