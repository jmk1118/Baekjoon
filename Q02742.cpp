#include <iostream>

int main(void)
{
	std::cin.tie(NULL);
	std::cin.sync_with_stdio(false);

	int a;
	std::cin >> a;

	for (int i = a; i > 0; i--)
		std::cout << i << "\n";
}