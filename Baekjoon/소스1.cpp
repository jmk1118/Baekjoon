#include <iostream>

int main(void)
{
	int n, k;
	std::cin >> n >> k;

	int coin[10];
	for (int i = 0; i < n; i++)
		std::cin >> coin[i];

	int sum = 0;
	int count = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (coin[i] <= k)
		{
			while (sum <= k)
			{
				sum = sum + coin[i];
				count = count + 1;
			}
			sum = sum - coin[i];
			count = count - 1;
		}
		if (sum == k)
			break;
	}
	
	std::cout << count;
}