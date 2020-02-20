#include <iostream>

int main(void)
{
	int n;
	std::string answer;
	int point[80] = { 0, };
	int sumPoint;
	
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> answer;
			
		if (answer[0] == 'O')
		{
			point[0] = 1;
			sumPoint = 1;
		}
		else
		{
			point[0] = 0;
			sumPoint = 0;
		}

		for (int p = 1; p < answer.size(); p++)
		{
			if (answer[p] == 'O')
			{
				if (answer[p - 1] == 'O')
					point[p] = point[p - 1] + 1;
				else
					point[p] = 1;
			}
			else
				point[p] = 0;

			sumPoint += point[p];
		}
		std::cout << sumPoint << "\n";
	}
}