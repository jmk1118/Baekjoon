#include <iostream>

int main(void)
{
	std::cin.tie(NULL);
	std::cin.sync_with_stdio(false);

	int a;
	std::cin >> a;

	for (int i = 1; i <= a; i++)
	{
		for (int p = 1; p <= i; p++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
}