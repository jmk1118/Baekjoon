#include <iostream>

int main(void)
{
	bool number[1000001] = { 0, };
	number[1] = true;

	int count;
	for (int i = 2; i <= 1000000; i++)
	{
		if (number[i] == false)
		{
			count = 2;
			while (i * count <= 1000000)
			{
				number[i * count] = true;
				count++;
			}
		}
	}

	int m, n;
	std::cin >> m >> n;
	for (int i = m; i <= n; i++)
	{
		if (number[i] == false)
		{
			std::cout << i << "\n";
		}
	}
}