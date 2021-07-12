#include <iostream>

int main(void)
{
	std::cin.tie(NULL);
	std::cin.sync_with_stdio(false);

	int a;
	std::cin >> a;

	int b, c;
	for (int i = 0; i < a; i++)
	{
		std::cin >> b >> c;
		std::cout << b + c << "\n";
	}
}