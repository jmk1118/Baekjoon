#include <iostream>

char board[50][50];
int checkPaint(int x, int y);

int main(void)
{
	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int o = 0; o < m; o++)
			std::cin >> board[i][o];

	int min = 32;
	int check;
	for (int i = 0; i <= n - 8; i++)
		for (int o = 0; o <= m - 8; o++)
		{
			check = checkPaint(i, o);
			if (min > check)
				min = check;
		}

	std::cout << min;
}

int checkPaint(int x, int y)
{
	int answer = 0;
	for (int i = x; i < x + 8; i++)
		for (int o = y; o < y + 8; o++)
		{
			if ((i + o) % 2 == 0 && board[i][o] != board[0][0])
				answer++;
			else if ((i + o) % 2 == 1 && board[i][o] == board[0][0])
				answer++;
		}

	if (answer > 32)
		return 64 - answer;
	else
		return answer;
}