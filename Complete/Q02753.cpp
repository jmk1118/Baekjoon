#include <iostream>

int main(void)
{
	int a;
	std::cin >> a;

	if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))
		std::cout << "1";
	else
		std::cout << "0";
}