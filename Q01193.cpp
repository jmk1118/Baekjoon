#include <iostream>

int main(void)
{
	int x;
	std::cin >> x;

	int sum = 0;
	int count = 1;
	while (sum < x)
	{
		sum += count;
		count++;
	}
	count--;

	if (count % 2 == 0)
	{
		std::cout << 1 + (x - sum + (count - 1)) << "/" << count - (x - sum + (count - 1));
	}
	else
	{
		std::cout << count - (x - sum + (count - 1)) << "/" << 1 + (x - sum + (count - 1));
	}
}