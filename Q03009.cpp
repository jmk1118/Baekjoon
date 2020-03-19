#include <iostream>

int main(void)
{
	int x1, y1;
	int x2, y2;
	int x3, y3;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	if (x1 == x2)
		std::cout << x3 << " ";
	else if (x2 == x3)
		std::cout << x1 << " ";
	else
		std::cout << x2 << " ";

	if (y1 == y2)
		std::cout << y3;
	else if (y2 == y3)
		std::cout << y1;
	else
		std::cout << y2;
}