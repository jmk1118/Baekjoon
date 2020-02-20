#include <iostream>

int main(void)
{
	int n;

	int min = 1000001;
	int max = -1000001;

	int now;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> now;

		if (min > now)
			min = now;
		if (max < now)
			max = now;
	}

	std::cout << min << " " << max;
}