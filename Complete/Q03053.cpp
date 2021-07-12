#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

int main(void)
{
	std::cout.setf(std::ios::fixed);
	std::cout.precision(6);
	double r;
	double pi = M_PI;
	std::cin >> r;

	std::cout << pi * r * r << "\n" << 2 * r * r;
}