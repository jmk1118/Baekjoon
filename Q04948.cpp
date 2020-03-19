#include <iostream>

int main(void)
{
	bool number[300001] = { 0, };
	number[1] = true;

	int count;
	for (int i = 2; i <= 300000; i++)
	{
		if (number[i] == false)
		{
			count = 2;
			while (i * count <= 300000)
			{
				number[i * count] = true;
				count++;
			}
		}
	}

	int n, answer;
	std::cin >> n;
	while (n != 0)
	{
		answer = 0;
		for (int i = n + 1; i <= 2 * n; i++)
		{
			if (number[i] == false)
				answer++;
		}
		std::cout << answer << "\n";

		std::cin >> n;
	}
}