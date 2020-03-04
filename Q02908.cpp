#include <iostream>

int main(void)
{
	std::string a, b;
	std::cin >> a >> b;

	char change;
	change = a[0];
	a[0] = a[2];
	a[2] = change;
	change = b[0];
	b[0] = b[2];
	b[2] = change;

	if (atoi(a.c_str()) > atoi(b.c_str()))
		std::cout << a;
	else
		std::cout << b;
}