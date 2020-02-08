#include <iostream>

int main(void)
{
	std::cout.precision(10);

	double a, b;
	std::cin >> a >> b;
	std::cout << a / b;
}