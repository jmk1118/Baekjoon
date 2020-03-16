#include <iostream>

int count(int leng);

int main(void)
{
	int t;
	std::cin >> t;

	int x, y;
	for (int i = 0; i < t; i++)
	{
		std::cin >> x >> y;

		std::cout << count(y - x) << "\n";
	}
}

int count(int leng)
{
	int i = 1;
	unsigned int check = 0;

	while (check * 2 <= leng)
	{
		check += i;
		i++;
	}

	i--;
	check -= i;


	if (check * 2 == leng)
		return (i - 1) * 2;
	else if (check * 2 + i >= leng)
		return (i - 1) * 2 + 1;
	else
		return (i - 1) * 2 + 2;
}