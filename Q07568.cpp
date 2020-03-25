#include <iostream>
#include <vector>

int main(void)
{
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> person;

	int h, t;
	for (int i = 0; i < n; i++)
	{
		std::cin >> h >> t;
		person.push_back(std::pair<int, int>(h, t));
	}

	int count;
	int answer[50];
	for (int i = 0; i < n; i++)
	{
		count = 0;
		for (int o = 0; o < n; o++)
		{
			if (i == o)
				continue;

			if (person.at(i).first < person.at(o).first)
				if (person.at(i).second < person.at(o).second)
					count++;
		}
		answer[i] = count;
	}

	for (int i = 0; i < n; i++)
		std::cout << answer[i] + 1 << "\n";
}