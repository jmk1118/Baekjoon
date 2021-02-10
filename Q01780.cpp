#include <iostream>

void bundle(int startX, int startY, int size);
int paper[2187][2187];
int answer[3];

int main(void)
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
		for (int o = 0; o < n; o++)
			std::cin >> paper[i][o];

	answer[0] = 0;
	answer[1] = 0;
	answer[2] = 0;

	bundle(0, 0, n);

	std::cout << answer[0] << std::endl << answer[1] << std::endl << answer[2];
}

void bundle(int startX, int startY, int size)
{
	int start = paper[startX][startY];
	if (size == 1)
	{
		answer[start + 1] += 1;
		return;
	}

	bool check = false;
	for (int i = 0; i < size; i++)
	{
		for (int o = 0; o < size; o++)
			if (start != paper[startX + i][startY + o])
			{
				check = true;
				break;
			}
		if (check)
			break;
	}

	if (check)
	{
		bundle(startX, startY, size / 3);
		bundle(startX, startY + size / 3, size / 3);
		bundle(startX, startY + 2 * (size / 3), size / 3);
		bundle(startX + size / 3, startY, size / 3);
		bundle(startX + size / 3, startY + size / 3, size / 3);
		bundle(startX + size / 3, startY + 2 * (size / 3), size / 3);
		bundle(startX + 2 * (size / 3), startY, size / 3);
		bundle(startX + 2 * (size / 3), startY + size / 3, size / 3);
		bundle(startX + 2 * (size / 3), startY + 2 * (size / 3), size / 3);
	}
	else
		answer[start + 1] += 1;
}