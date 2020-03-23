#include <iostream>

int factorial(int n);

int main(void)
{
	int n;
	std::cin >> n;

	std::cout << factorial(n);
}

int factorial(int n)
{
	if (n <= 1)
		return 1;

	return n * factorial(n - 1);
}