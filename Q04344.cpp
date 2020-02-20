#include <iostream>

int main(void)
{
	std::cout.setf(std::ios::fixed);
	std::cout.precision(3);

	int c;
	std::cin >> c;

	int n;
	int point[1000];
	float avg;
	float count;

	for (int i = 0; i < c; i++)
	{
		avg = 0;
		count = 0;
		std::cin >> n;

		for (int o = 0; o < n; o++)
		{
			std::cin >> point[o];
			avg += point[o];
		}
		avg = avg / n;
		for (int o = 0; o < n; o++)
		{
			if (point[o] > avg)
				count++;
		}
		std::cout << count / n * 100 << "%\n";
	}
}