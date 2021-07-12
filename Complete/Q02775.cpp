#include <iostream>

int main(void)
{
	int t;
	std::cin >> t;

	int people[15][15];
	int sum = 0;
	for (int i = 1; i < 15; i++)
	{
		people[0][i] = i;
	}
	for (int i = 1; i < 15; i++)
	{
		for (int o = 1; o < 15; o++)
		{
			for (int p = 1; p <= o; p++)
			{
				sum += people[i - 1][p];
			}
			people[i][o] = sum;
			sum = 0;
		}
	}
	int k, n;
	for (int i = 0; i < t; i++)
	{
		std::cin >> k >> n;

		std::cout << people[k][n] << "\n";
	}
}