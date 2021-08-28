#include <iostream>
#include <algorithm>

int count[1000001];

int main(void)
{
	int X;
	std::cin >> X;

	count[1] = 0;
	count[2] = 1;
	count[3] = 1;
	for (int i = 4; i <= X; i++)
	{
		if (i % 6 == 0)
			count[i] = std::min(std::min(count[i / 3], count[i / 2]), count[i - 1]) + 1;
		else if (i % 3 == 0)
			count[i] = std::min(count[i / 3], count[i - 1]) + 1;
		else if (i % 2 == 0)
			count[i] = std::min(count[i / 2], count[i - 1]) + 1;
		else
			count[i] = count[i - 1] + 1;
	}

	std::cout << count[X];
}