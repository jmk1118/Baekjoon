#include <iostream>

int main(void)
{
	bool number[1001] = { 0, };
	number[1] = true;

	int count;
	for (int i = 2; i <= 1000; i++)
	{
		if (number[i] == false)
		{
			count = 2;
			while (i * count <= 1000)
			{
				number[i * count] = true;
				count++;
			}
		}
	}
	
	int n;
	int now;
	int answer = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> now;
		if (number[now] == false)
			answer++;
	}

	std::cout << answer;
}