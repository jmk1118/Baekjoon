#include <iostream>

char starPosition[7000][7000];
void star(int n, int x, int y);

int main(void)
{
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++)
		for (int o = 1; o <= n; o++)
			starPosition[o][i] = ' ';

	star(n, 1, 1);

	for (int i = 1; i <= n; i++)
	{
		for (int o = 1; o <= n; o++)
			std::cout << starPosition[o][i];

		std::cout << "\n";
	}
}

void star(int n, int x, int y)
{
	if (n == 3)
	{
		starPosition[x][y] = '*';
		starPosition[x + 1][y] = '*';
		starPosition[x + 2][y] = '*';
		starPosition[x][y + 1] = '*';
		starPosition[x + 1][y + 1] = ' ';
		starPosition[x + 2][y + 1] = '*';
		starPosition[x][y + 2] = '*';
		starPosition[x + 1][y + 2] = '*';
		starPosition[x + 2][y + 2] = '*';
	}
	else
	{
		star(n / 3, x, y);
		star(n / 3, x + n / 3, y);
		star(n / 3, x + (2 * n) / 3, y);
		star(n / 3, x, y + n / 3);

		star(n / 3, x + (2 * n) / 3, y + n /3);
		star(n / 3, x, y + (2 * n) / 3);
		star(n / 3, x + n / 3, y + (2 * n) / 3);
		star(n / 3, x + (2 * n) / 3, y + (2 * n) / 3);
	}
}