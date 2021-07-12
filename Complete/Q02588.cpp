#include <iostream>

int main(void)
{
	int a, b;
	std::cin >> a >> b;
	std::cout << a * (b % 10) << std::endl;
	std::cout << a * ((b % 100) / 10) << std::endl;
	std::cout << a * (b / 100) << std::endl;
	std::cout << a * b;
}