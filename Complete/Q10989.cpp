#include <iostream>

int main(void)
{
	int n;
	int number[10001] = { 0, };

	std::cin >> n;
	int check;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &check);
		number[check]++;
	}

	for (int i = 0; i < 10001; i++)
		for (int o = 0; o < number[i]; o++)
			printf("%d\n", i);
}