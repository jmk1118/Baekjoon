#include <iostream>

int main(void)
{
	std::cin.tie(NULL);
	std::cin.sync_with_stdio(false);

	int a;
	std::cin >> a;

	for (int i = 1; i <= a; i++)
		std::cout << i << "\n";
}