#include <iostream>
#include <deque>

int main(void)
{
	int n, m;
	std::cin >> n >> m;

	std::deque<int> queue;
	for (int i = 0; i < n; i++)
		queue.push_back(i + 1);

	int tem, count, check;
	int answer = 0;
	for (int i = 0; i < m; i++)
	{
		std::cin >> check;
		count = 0;

		while (queue.front() != check)
		{
			tem = queue.front();
			queue.pop_front();
			queue.push_back(tem);
			count++;
		}

		if (count <= queue.size() / 2)
			answer += count;
		else
			answer += (queue.size() - count);

		queue.pop_front();
	}

	std::cout << answer << std::endl;
}