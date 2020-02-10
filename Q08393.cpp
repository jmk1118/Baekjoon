#include <iostream>

int main(void)
{
	int a;
	std::cin >> a;

	int sum = 0;
	for (int i = 1; i <= a; i++)
		sum += i;
	std::cout << sum;
}