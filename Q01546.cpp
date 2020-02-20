#include <iostream>

int main(void)
{
	std::cout.precision(4);

	int n;
	int point[1000];
	float max = 0;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> point[i];

		if (max < point[i])
			max = point[i];
	}

	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (point[i] / max) * 100;
	}
	
	std::cout << sum / n;
}