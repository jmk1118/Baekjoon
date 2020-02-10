#include <iostream>

int main(void)
{
	int h, m;
	std::cin >> h >> m;

	if (m >= 45)
		std::cout << h << " " << m - 45;
	else if (h == 0)
		std::cout << "23" << " " << 60 - (45 - m);
	else
		std::cout << h - 1 << " " << 60 - (45 - m);
}