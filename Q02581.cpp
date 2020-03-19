#include <iostream>

int main(void)
{
	bool number[10001] = { 0, };
	number[1] = true;

	int count;
	for (int i = 2; i <= 10000; i++)
	{
		if (number[i] == false)
		{
			count = 2;
			while (i * count <= 10000)
			{
				number[i * count] = true;
				count++;
			}
		}
	}

	int m, n;
	std::cin >> m >> n;
	int min = 10001;
	int sum = 0;
	for (int i = m; i <= n; i++)
	{
		if (number[i] == false)
		{
			if (i < min)
				min = i;

			sum += i;
		}
	}
	if (sum == 0)
		std::cout << -1;
	else
		std::cout << sum << "\n" << min;
}