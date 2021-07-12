#pragma warning(disable: 4996)
#include <iostream>
#include <queue>

int main(void)
{
	std::priority_queue<int> pq;

	int n;
	scanf("%d", &n);

	int input;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		if (input == 0 && pq.size() == 0)
			printf("0\n");
		else if (input == 0)
		{
			printf("%d\n", pq.top());
			pq.pop();
		}
		else
			pq.push(input);
	}
}