#include <iostream>

int main(void)
{
	int n;
	std::cin >> n;

	int sum = 1;
	int count = 1;
	while (sum < n)
	{
		sum += count * 6;
		count++;
	}

	std::cout << count;
}