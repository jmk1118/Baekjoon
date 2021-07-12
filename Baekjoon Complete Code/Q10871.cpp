#include <iostream>

int main(void)
{
	std::cin.tie(NULL);
	std::cin.sync_with_stdio(false);

	int n, x;
	std::cin >> n >> x;

	int a;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> a;
		if (a < x)
			std::cout << a << " ";
	}
}