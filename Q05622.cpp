#include <iostream>

int main(void)
{
	std::string grandmather;
	std::cin >> grandmather;

	int time = 0;

	for (int i = 0; i < grandmather.size(); i++)
	{
		time += (grandmather[i] - 'A') / 3 + 3;
		if (grandmather[i] == 'S' || grandmather[i] == 'V' || grandmather[i] == 'Y' || grandmather[i] == 'Z')
			time--;
	}

	std::cout << time;
}