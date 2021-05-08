#include <iostream>

int n, m;
int answer[9];

void backTracking(int nowlength, int value);

int main(void) 
{
	std::cin >> n >> m;

	for (int i = 1; i <= n - m + 1; i++)
	{
		answer[1] = i;
		if (m == 1)
		{
			std::cout << answer[1] << std::endl;
			continue;
		}

		for (int o = i + 1; o <= n; o++)
			backTracking(2, o);
	}
}

void backTracking(int nowlength, int value)
{
	answer[nowlength] = value;
	if (nowlength >= m)
	{
		for (int i = 1; i <= m; i++)
			std::cout << answer[i] << " ";
		std::cout << std::endl;

		return;
	}

	for (int i = value + 1; i <= n; i++)
	{
		backTracking(nowlength + 1, i);
	}
}