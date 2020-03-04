#include <iostream>

int main(void)
{
	int n;
	std::string input;
	bool alpha[36] = { 0, };
	
	std::cin >> n;
	int count = n;
	for (int i = 0; i < n; i++)
	{
		for (int o = 0; o < 36; o++)
		{
			alpha[o] = false;
		}

		std::cin >> input;
		alpha[input[0] - 'a'] = true;
		for (int o = 1; o < input.size(); o++)
		{
			if (input[o - 1] == input[o])
				continue;
			else if (alpha[input[o] - 'a'] == true)
			{
				count--;
				break;
			}

			alpha[input[o] - 'a'] = true;
		}
	}

	std::cout << count;
}