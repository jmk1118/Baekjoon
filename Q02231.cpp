#include <iostream>

int main(void)
{
	int n;
	std::cin >> n;

	int answer = 2000000;
	int now = 0;
	for (int i = 0; i < n; i++)
	{
		now = i;
		now += i / 1000000;
		now += (i % 1000000 - i % 100000) / 100000;
		now += (i % 100000 - i % 10000) / 10000;
		now += (i % 10000 - i % 1000) / 1000;
		now += (i % 1000 - i % 100) / 100;
		now += (i % 100 - i % 10) / 10;
		now += i % 10;
		if (now == n && now < answer)
			answer = i;
	}

	if (answer == 2000000)
		std::cout << 0;
	else
		std::cout << answer;
}