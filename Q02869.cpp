#include <iostream>

int main(void)
{
	int a, b, v;
	std::cin >> a >> b >> v;

	if ((v - a) % (a - b) == 0)
		std::cout << (v - a) / (a - b) + 1;
	else
		std::cout << (v - a) / (a - b) + 2;
}