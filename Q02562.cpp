#include <iostream>

int main(void)
{
	int question[9];

	int max = 0;
	int maxNumber = 0;

	for (int i = 0; i < 9; i++)
	{
		std::cin >> question[i];
		if (max < question[i])
		{
			max = question[i];
			maxNumber = i;
		}
	}
	std::cout << max << "\n" << maxNumber + 1;
}