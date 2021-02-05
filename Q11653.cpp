#include <iostream>

int main(void)
{
	int n;
	std::cin >> n;

	int i;
	while (n != 1)
	{
		for (i = 2; i <= n; i++)
		{
			if (n % i == 0)
			{
				std::cout << i << std::endl;
				n = n / i;
				break;
			}
		}
	}
}