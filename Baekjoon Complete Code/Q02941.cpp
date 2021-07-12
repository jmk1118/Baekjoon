#include <iostream>

int main(void)
{
	std::string input;
	std::cin >> input;

	int count = 0;
	for (int i = 0; i < input.size(); i++)
	{
		count++;
		if (input[i] == '=')
		{
			if (input[i - 1] == 'z')
				if (i > 1 && input[i - 2] == 'd')
					count -= 1;

			count -= 1;
		}
		else if (input[i] == '-')
			count -= 1;
		else if (input[i] == 'j')
			if (i > 0 && (input[i - 1] == 'l' || input[i - 1] == 'n'))
				count -= 1;
	}

	std::cout << count;
}