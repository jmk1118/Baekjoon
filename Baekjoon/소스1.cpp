#include <iostream>

int main(void)
{
	std::cin.tie(NULL);
	std::cin.sync_with_stdio(false);

	int a, b;

	while (std::cin >> a >> b)
	{
		std::cout << a + b << "\n";
	}
}