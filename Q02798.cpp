#include <iostream>

int main(void)
{
	int n, m;
	std::cin >> n >> m;

	int card[100];
	for (int i = 0; i < n; i++)
		std::cin >> card[i];

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int o = i + 1; o < n; o++)
		{
			for (int p = o + 1; p < n; p++)
			{
				if (card[i] + card[o] + card[p] > max && card[i] + card[o] + card[p] <= m)
					max = card[i] + card[o] + card[p];
			}
		}
	}

	std::cout << max;
}