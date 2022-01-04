#include <iostream>

int main(void)
{
	int remainder[42] = { 0, };

	int now;
	for (int i = 0; i < 10; i++)
	{
		std::cin >> now;
		remainder[now % 42]++;
	}

	int sum = 0;
	for (int i = 0; i < 42; i++)
	{
		if (remainder[i] != 0)
			sum++;
	}

	std::cout << sum;
}