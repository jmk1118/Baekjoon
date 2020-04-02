#include <iostream>
#include <algorithm>

int number[500000];

int main(void)
{
	std::cout << std::fixed;
	std::cout.precision(0);
	int n;
	std::cin >> n;

	int count[8001] = { 0, };
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> number[i];
		sum += number[i];
		if (number[i] >= 0)
			count[number[i]]++;
		else
			count[number[i] * -1 + 4000]++;
	}
	std::sort(number, number + n);
	if (sum / n == 0)
		std::cout << "0\n";
	else
		std::cout << (double)sum / n << "\n";
	std::cout << number[n / 2] << "\n";

	int max = 0;
	int answer = 0;
	bool check = 1;
	for (int i = 8000; i > 4000; i--)
	{
		if (count[i] > max)
		{
			max = count[i];
			answer = (i - 4000) * -1;
			check = 0;
		}
		else if (count[i] == max && check == 0)
		{
			answer = (i - 4000) * -1;
			check = 1;
		}
	}
	for (int i = 0; i <= 4000; i++)
	{
		if (count[i] > max)
		{
			max = count[i];
			answer = i;
			check = 0;
		}
		else if (count[i] == max && check == 0)
		{
			answer = i;
			check = 1;
		}
	}

	std::cout << answer << "\n";
	std::cout << number[n - 1] - number[0] << "\n";
}