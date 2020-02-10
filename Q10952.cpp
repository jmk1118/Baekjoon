#include <iostream>

int main(void)
{
	std::cin.tie(NULL);
	std::cin.sync_with_stdio(false);

	int a, b;

	std::cin >> a >> b;

	while (a != 0 || b != 0)
	{
		std::cout << a + b << "\n";
		std::cin >> a >> b;
	}
}