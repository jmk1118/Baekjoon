#include <iostream>
#include <vector>

int main(void)
{
	int N;
	int number;
	std::vector<int> A;
	
	std::cin >> N;
	std::cin >> number;
	A.push_back(number);

	for (int i = 2; i <= N; i++)
	{
		std::cin >> number;
		if (number > A.back())
			A.push_back(number);
		else
		{
			for (int o = 0; o < A.size(); o++)
			{
				if (A.at(o) >= number)
				{
					A.at(o) = number;
					break;
				}
			}
		}
	}

	std::cout << A.size();
}