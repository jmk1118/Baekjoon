#include <iostream>
#include <string>

int main(void)
{
	int stack[10000] = { 0, };
	int n;
	std::cin >> n;

	std::string order;
	int num;
	int count = -1;
	for (int i = 0; i < n; i++)
	{
		std::cin >> order;
		if (order.compare("push") == 0)
		{
			std::cin >> num;
			count = count + 1;
			stack[count] = num;
		}
		else if (order.compare("pop") == 0)
		{
			if (count == -1)
			{
				std::cout << -1 << "\n";
				continue;
			}
			std::cout << stack[count] << "\n";
			count = count - 1;
		}
		else if (order.compare("top") == 0)
		{
			if (count == -1)
			{
				std::cout << -1 << "\n";
				continue;
			}
			std::cout << stack[count] << "\n";
		}
		else if (order.compare("size") == 0)
			std::cout << count + 1 << "\n";
		else if (order.compare("empty") == 0)
		{
			if (count == -1)
				std::cout << 1 << "\n";
			else
				std::cout << 0 << "\n";
		}
	}
}