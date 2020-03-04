#include <iostream>

int main(void)
{
	int n;
	std::string number;
	int sum = 0;

	std::cin >> n >> number;
	for (int i = 0; i < n; i++)
	{
		sum += number[i] - '0';
	}

	std::cout << sum;
}