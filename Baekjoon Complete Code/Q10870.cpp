#include <iostream>

int  Fibonacci(int n);

int main(void)
{
	int n;
	std::cin >> n;

	std::cout << Fibonacci(n);
}

int  Fibonacci(int n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return 0;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}