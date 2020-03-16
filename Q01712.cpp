#include <iostream>

int main(void)
{
	int a, b, c;
	std::cin >> a >> b >> c;

	if (c == b)
	{
		std::cout << -1;
		return 0;
	}

	int answer = a / (c - b);

	if (c - b < 0)
		std::cout << -1;
	else
		std::cout << answer + 1;
}