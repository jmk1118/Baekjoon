#include <iostream>
#include <algorithm>

int main(void)
{
	int n;
	int number[100000];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> number[i];

	int answer = -1001;
	int nowmax = -1001;

	for (int i = 0; i < n; i++)
	{
		nowmax = std::max(nowmax + number[i], number[i]);
		answer = std::max(answer, nowmax);
	}

	std::cout << answer;
}