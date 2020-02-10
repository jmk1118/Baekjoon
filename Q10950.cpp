#include <iostream>

int main(void)
{
	int a;
	std::cin >> a;

	int b, c;
	for (int i = 0; i < a; i++)
	{
		std::cin >> b >> c;
		std::cout << b + c << std::endl;
	}
}