#include <iostream>

void DFS(int number, int depth);

int answer[8];
int check[9] = { 0, };
int n, m;

int main(void)
{
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		check[i] = 1;
		DFS(i, 0);
		check[i] = 0;
	}
}

void DFS(int number, int depth)
{
	answer[depth] = number;
	if (depth == m - 1)
	{
		for (int i = 0; i < m; i++)
			std::cout << answer[i] << " ";
		std::cout << "\n";

		answer[depth] = NULL;
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (check[i] == 0)
			{
				check[i] = 1;
				DFS(i, depth + 1);
				check[i] = 0;
			}
		}
	}
}