#include <iostream>

void bundle(int startX, int startY, int size);
char image[64][64];

int main(void)
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
		for (int o = 0; o < n; o++)
			std::cin >> image[i][o];

	bundle(0, 0, n);
}

void bundle(int startX, int startY, int size)
{
	char start = image[startX][startY];
	if (size == 1)
	{
		std::cout << start;
		return;
	}

	bool check = false;
	for (int i = 0; i < size; i++)
	{
		for (int o = 0; o < size; o++)
			if (start != image[startX + i][startY + o])
			{
				check = true;
				break;
			}
		if (check)
			break;
	}

	if (check)
	{
		std::cout << "(";
		bundle(startX, startY, size / 2);
		bundle(startX, startY + size / 2, size / 2);
		bundle(startX + size / 2, startY, size / 2);
		bundle(startX + size / 2, startY + size / 2, size / 2);
		std::cout << ")";
	}
	else
		std::cout << start;
}